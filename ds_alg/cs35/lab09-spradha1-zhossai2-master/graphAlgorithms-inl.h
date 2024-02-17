/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V, E, W> *g)
{
    STLStack<V> stack;
    STLHashTable<V, bool> visited;
    stack.push(src);
    visited.insert(src, true);
    while (!stack.isEmpty())
    {
        V current = stack.pop();
        if (current == dest)
        {
            return true;
        }
        vector<V> neighbors = g->getNeighbors(current);
        for (int i = 0; i < neighbors.size(); i++)
        {
            if (!visited.contains(neighbors[i]))
            {
                stack.push(neighbors[i]);
                visited.insert(neighbors[i], true);
            }
        }
    }
    return false;
}

// ignores cost and returns path w/ shortest # of edges
// FIXME: still pseudocode'ish, need to confirm methods name and need to test
template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V, E, W> *g)
{
    vector<V> path; // empty path
    STLQueue<V> queue;

    STLHashTable<V, V> previous;

    // Which dictionary implemenation to be used?
    queue.enqueue(src);
    previous.insert(src, src);

    while (!queue.isEmpty())
    {
        V current = queue.dequeue();
        if (current == dest)
        {
            // V temp = current;
            while (current != src)
            {
                // path.insert(path.begin(), previous.get(temp));
                path.insert(path.begin(), current);
                // temp = previous.get(temp);
                current = previous.get(current);
            }
            path.insert(path.begin(), src);
            return path;
        }
        else
        {
            for (int i = 0; i < g->getNeighbors(current).size(); i++)
            {
                if (!previous.contains(g->getNeighbors(current).at(i)))
                {
                    previous.insert(g->getNeighbors(current).at(i), current);
                    queue.enqueue(g->getNeighbors(current).at(i));
                }
            }
        }
    }
    return path;
}

// FIXME: still pseudocode'ish, need to confirm methods name and need to test
template <typename V, typename E, typename W>
Dictionary<V, W> *singleSourceShortestPath(V src, Graph<V, E, W> *g)
{
    Dictionary<V, W> *cost = new STLHashTable<V,W>();
    STLMinPriorityQueue<W, V> pq;
    cost->insert(src, 0);
    pq.insert(0, src);
    while (!pq.isEmpty()){
        W currPriority = pq.peekPriority();
        V currVertex = pq.remove();
        W currCost = cost->get(currVertex);
        // Ignore any stale priorities that are higher
        if (currCost == currPriority){
            vector<Edge<V,E,W>> outgoingEdges = g->getOutgoingEdges(currVertex);
            for (Edge<V,E,W> e : outgoingEdges){
                V next = e.getDestination();
                W newCost = currCost + e.getWeight();
                if (!cost->contains(next)){
                    cost->insert(next, newCost);
                    pq.insert(newCost, next);
                }
                else if (newCost < cost->get(next)){
                    // Lower cost found!
                    cost->update(next, newCost);
                    // no update in PQ, just insert again
                    pq.insert(newCost, next);
                }
            }
        }
    }
    return cost;
}
