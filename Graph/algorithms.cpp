#include <iostream>
#include <map>
#include <numeric>
#include <set>

#include "Graph.hpp"

/* A* algorithm. While there is an unvisited vertex, select the one with minimum cost and study its neighbors. Stops when the current vertex is the destination. */
std::vector<const Edge*>* Graph::algo_astar(const Vertex* source, const Vertex* destination) {
    unsigned int                           inf_unsigned = -1; inf_unsigned /= 2;
    int                                    inf_signed   = inf_unsigned;
    bool                                   path_found   = false;
    std::map<const Vertex*, double>        costs;
    std::map<const Vertex*, const Vertex*> previous;
    std::set<const Vertex*>                search;
    std::set<const Vertex*>                visited;
    /* initialization */
    for(const Vertex* v : *graph_representation->getVertices()) {
        costs[v]    = inf_signed;
        previous[v] = 0;
    }
    costs[source] = 0;
    search.insert(source);
    while(!search.empty()) {
        /* finds the best potential vertex and extracts it from the list */
        std::set<const Vertex*>::iterator it_min;
        it_min = std::min_element(search.begin(), search.end(), [&](const Vertex* v1, const Vertex* v2) { return costs[v1]+v1->distanceTo(destination)<costs[v2]+v2->distanceTo(destination); });
        const Vertex* v_min = *it_min;
        search.erase(it_min);
        visited.insert(v_min);
        /* stop if destination is found */
        if(v_min==destination) {
            path_found = true;
            break;
        }
        /* same treatment for all neighbors */
        std::vector<Vertex*> neighbors = orientation==ONE_WAY ? graph_representation->get_direct_neighbors(v_min, orientation) : graph_representation->get_all_neighbors(v_min);
        for(const Vertex* v : neighbors) {
            if(!visited.count(v)) {
                search.insert(v);
                const_cast<Vertex*>(v)->setColor(Constants::VERTEX_VISITED_COLOR_R, Constants::VERTEX_VISITED_COLOR_G, Constants::VERTEX_VISITED_COLOR_B);
                double diff = costs[v_min] + v_min->distanceTo(v);
                if(diff<costs[v]) {
                    costs[v]    = diff;
                    previous[v] = v_min;
                }
            }
        }
    }
    /* prints the path */
    const_cast<Vertex*>(destination)->setColor(Constants::EDGE_ALGO_DESTINATION_COLOR_R, Constants::EDGE_ALGO_DESTINATION_COLOR_G, Constants::EDGE_ALGO_DESTINATION_COLOR_B);
    if(path_found) {
        const Vertex* v = destination;
        std::vector<const Edge*>* path = new std::vector<const Edge*>;
        while(v!=source) {
            Edge* e = graph_representation->get_edge_from_to(v, previous[v]);
            e->setColor(Constants::EDGE_ALGO_RESULT_COLOR_R, Constants::EDGE_ALGO_RESULT_COLOR_G, Constants::EDGE_ALGO_RESULT_COLOR_B);
            path->push_back(e);
            v = previous[v];
        }
        return path;
    }
    else {
        return 0;
    }
}

/* Dijkstra algorithm. While there is an unvisited vertex, select the one with minimum cost and study its neighbors. Stops when the current vertex is the destination. */
std::vector<const Edge*>* Graph::algo_dijkstra(const Vertex* source, const Vertex* destination) {
    unsigned int                           inf_unsigned = -1; inf_unsigned /= 2;
    int                                    inf_signed   = inf_unsigned;
    bool                                   path_found   = false;
    std::map<const Vertex*, double>        costs;
    std::map<const Vertex*, const Vertex*> previous;
    std::set<const Vertex*>                search;
    std::set<const Vertex*>                visited;
    /* initialization */
    for(const Vertex* v : *graph_representation->getVertices()) {
        costs[v]    = inf_signed;
        previous[v] = 0;
    }
    costs[source] = 0;
    search.insert(source);
    while(!search.empty()) {
        /* finds the best potential vertex and extracts it from the list */
        std::set<const Vertex*>::iterator it_min;
        it_min = std::min_element(search.begin(), search.end(), [&](const Vertex* v1, const Vertex* v2) { return costs[v1]<costs[v2]; });
        const Vertex* v_min = *it_min;
        search.erase(it_min);
        visited.insert(v_min);
        /* stop if destination is found */
        if(v_min==destination) {
            path_found = true;
            break;
        }
        /* same treatment for all neighbors */
        std::vector<Vertex*> neighbors = orientation==ONE_WAY ? graph_representation->get_direct_neighbors(v_min, orientation) : graph_representation->get_all_neighbors(v_min);
        for(const Vertex* v : neighbors) {
            if(!visited.count(v)) {
                search.insert(v);
                const_cast<Vertex*>(v)->setColor(Constants::VERTEX_VISITED_COLOR_R, Constants::VERTEX_VISITED_COLOR_G, Constants::VERTEX_VISITED_COLOR_B);
                double diff = costs[v_min] + v_min->distanceTo(v);
                if(diff<costs[v]) {
                    costs[v]    = diff;
                    previous[v] = v_min;
                }
            }
        }
    }
    /* prints the path */
    const_cast<Vertex*>(destination)->setColor(Constants::EDGE_ALGO_DESTINATION_COLOR_R, Constants::EDGE_ALGO_DESTINATION_COLOR_G, Constants::EDGE_ALGO_DESTINATION_COLOR_B);
    if(path_found) {
        const Vertex* v = destination;
        std::vector<const Edge*>* path = new std::vector<const Edge*>;
        while(v!=source) {
            Edge* e = graph_representation->get_edge_from_to(v, previous[v]);
            e->setColor(Constants::EDGE_ALGO_RESULT_COLOR_R, Constants::EDGE_ALGO_RESULT_COLOR_G, Constants::EDGE_ALGO_RESULT_COLOR_B);
            path->push_back(e);
            v = previous[v];
        }
        return path;
    }
    else {
        return 0;
    }
}

/* Ford Fulkerson algorithm. While there is a path from source to sink, find the smallest capacity of the path, add it to the max_flow and to every reverse edge of the path, and remove it from every edge in the path. When no more path is found, max_flow has the maximum flow and is returned. */
int Graph::algo_ford_fulkerson(const Vertex* source, const Vertex* sink) {
    int    max_flow          = 0;
    Graph* residual_graph    = new Graph(type, nb_vertices);
    *residual_graph          = *this;
    const Vertex* res_source = residual_graph->graph_representation->getVertices()->at(source->getId());
    const Vertex* res_sink   = residual_graph->graph_representation->getVertices()->at(sink->getId());
    /* While there is a path from source to sink */
    bool valid_path = true;
    std::vector<const Vertex*>* path    = new std::vector<const Vertex*>;
    std::set<const Vertex*>*    visited = new std::set<const Vertex*>;
    do {
        visited->clear();
        visited->insert(res_source);
        path->clear();
        path->push_back(res_source);
        valid_path = algo_ford_fulkerson_callback_path(const_cast<const Graph *>(residual_graph), path, visited, res_source, res_sink);
        if(valid_path) {
            /* finds the minimum capacity */
            int min_flow = residual_graph->graph_representation->get_capacity_from_to(res_source, path->at(1));
            for(std::vector<const Vertex*>::iterator it=path->begin() ; it!=path->end() ; it++) {
                if(*it!=res_sink) {
                    graph_representation->get_edge_from_to((*it)->getId(), (*(it+1))->getId())->setColor(Constants::EDGE_ALGO_RESULT_COLOR_R, Constants::EDGE_ALGO_RESULT_COLOR_G, Constants::EDGE_ALGO_RESULT_COLOR_B);
                    int f = residual_graph->graph_representation->get_capacity_from_to(*it, *(it+1));
                    if(f<min_flow) min_flow = f;
                }
            }
            /* adds the capacity to the max flow */
            max_flow += min_flow;
            /* updates the capacities */
            for(std::vector<const Vertex*>::iterator it=path->begin() ; it!=path->end() ; it++) {
                if(*it!=res_sink) {
                    residual_graph->graph_representation->set_capacity_from_to(*it, *(it+1), residual_graph->graph_representation->get_capacity_from_to(*it, *(it+1))-min_flow);
                    residual_graph->graph_representation->set_capacity_from_to(*(it+1), *it, residual_graph->graph_representation->get_capacity_from_to(*(it+1), *it)+min_flow);
                }
            }
        }
    } while(valid_path);
    delete path;
    delete visited;
    delete residual_graph;
    return max_flow;
}

/* Ford Fulkerson algorithm callback method. Tries to find a valid path from source to sink and returns true if a path is found. Otherwise returns false. */
bool Graph::algo_ford_fulkerson_callback_path(const Graph* graph, std::vector<const Vertex*>* path, std::set<const Vertex*>* visited, const Vertex* source, const Vertex* sink) {
    for(const Vertex* v : graph->graph_representation->get_direct_neighbors(path->back(), orientation)) {
        if(graph->graph_representation->get_capacity_from_to(path->back(), v)>0) {
            if(v==sink) {
                path->push_back(v);
                return true;
            }
            else if(v!=source && visited->count(v)==0) {
                const_cast<Vertex*>(v)->setColor(0, 255, 255);
                path->push_back(v);
                visited->insert(v);
                bool res = algo_ford_fulkerson_callback_path(graph, path, visited, source, sink);
                if(res) {
                    return true;
                }
                else {
                    path->erase((path->end()-1));
                    visited->erase(v);
                }
            }
        }
    }
    return false;
}

/* Prim algorithm. While there are edges in the set, select the one with less capacity, include it in the subgraph and study its two vertices. */
std::vector<const Edge*>* Graph::algo_prim() {
    std::set<const Vertex*>   visited;
    std::set<const Edge*>     search;
    std::vector<const Edge*> *sub_graph = new std::vector<const Edge*>;
    /* begin with a random Vertex */
    Vertex* v_begin = graph_representation->getVertices()->at(0);
    visited.insert(v_begin);
    /* add all adjacency edges */
    for(Vertex* v : graph_representation->get_all_neighbors(v_begin)) { search.insert(graph_representation->get_edge_from_to(v_begin, v)); }
    while(!search.empty()) {
        std::set<const Edge*>::iterator it_min;
        it_min = std::min_element(search.begin(), search.end(), [](const Edge* e1, const Edge* e2){ return e1->getCapacityV1ToV2()<e2->getCapacityV1ToV2(); });
        const Edge* e_min = *it_min;
        search.erase(it_min);
        Vertex* v1 = e_min->getV1();
        Vertex* v2 = e_min->getV2();
        if(!visited.count(v1) || !visited.count(v2)) {
            sub_graph->push_back(e_min);
            if(!visited.count(v1)) {
                visited.insert(v1);
                /* add all adjacency edges */
                for(Vertex* v : graph_representation->get_all_neighbors(v1)) { search.insert(graph_representation->get_edge_from_to(v1, v)); }
            }
            else {
                visited.insert(v2);
                /* add all adjacency edges */
                for(Vertex* v : graph_representation->get_all_neighbors(v2)) { search.insert(graph_representation->get_edge_from_to(v2, v)); }
            }
        }
    }
    /* displays the sub graph */
    for(const Edge* e : *sub_graph) const_cast<Edge*>(e)->setColor(Constants::EDGE_ALGO_RESULT_COLOR_R, Constants::EDGE_ALGO_RESULT_COLOR_G, Constants::EDGE_ALGO_RESULT_COLOR_B);
    return sub_graph;
}
