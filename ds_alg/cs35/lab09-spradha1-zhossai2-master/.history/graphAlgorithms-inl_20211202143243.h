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
    vector<Edge<V, E, W>> outgoingEdges = g->getOutgoingEdges(src);

    for (int i = 0; i < outgoingEdges.size(); i++)
    {
        if (outgoingEdges.at(i).getDestination() == dest)
        {
            return true;
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
    Queue<V> queue;

    Dictionary<V, V> previous;

    // Which dictionary implemenation to be used?
    queue.enqueue(src);
    previous.insert(start, start);

    while (!queue.isEmpty())
    {
        V current = queue.dequeue();
        if (current == end)
        {
            V temp = current;
            while (temp != src)
            {
                path.insert(path.begin(), previous.get(temp));
                temp = previous.get(temp);
            }
            return path;
        }
        else
        {
            for (int i = 0; i < current.getNeighbors().size(); i++)
            {
                if (!previous.contains(current.getNeighbors().at(i)))
                {
                    previous.insert(current.getNeighbors().at(i), current)
                        queue.enqueue(current.getNeighbors().at(i));
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
    Dictionary<V, W> *cost;
    STLMinPriorityQueue<W, V> *pq;
    // What is Q from the pseudocode?
    cost->insert(src, Q);
    pq->insert(Q, src);

    while (!pq->isEmpty())
    {
        W currPriority = pq->peekPriority();
        V currVertex = pq->remove();
        W currCost = cost->get(currVertex);

        // Ignore any stale priorities that are higher

        if (currCost == currPriority)
        {
            for (auto e : currVertex.getOutgoingEdges())
            {
                V next = e.getDestination();
                W newCost = currCost + e.getWeight();
                if (!cost->contains(next))
                {
                    cost->insert(next, newCost);
                    pq->insert(newCost, next);
                }
                else if (newCost < cost->get(next))
                {
                    // Lower cost found!
                    cost->update(next, newCost);
                    // no update in PQ, just insert again
                    pq->insert(newCost, next);
                }
            }
        }
    }
    return cost;
}
