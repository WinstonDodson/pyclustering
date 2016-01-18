#ifndef _ADJACENCY_H_
#define _ADJACENCY_H_

#include <vector>
#include <unordered_set>


/***********************************************************************************************
*
* @brief   Enumaration of connection structures between nodes.
*
***********************************************************************************************/
enum connection_t {
	STATIC_STRUCTURE_NONE,
	STATIC_STRUCTURE_ALL_TO_ALL,
	STATIC_STRUCTURE_FOUR,
	STATIC_STRUCTURE_EIGHT,
	STATIC_STRUCTURE_BIDIRECTIONAL,
	DYNAMIC_STRUCTURE,
};


/***********************************************************************************************
*
* @brief   Abstract class of the adjacency collection that provides interface to control collection.
*
***********************************************************************************************/
template <class TypeNode, template<class> class Container>
class adjacency_collection {
protected:
    Container<TypeNode>     m_adjacency;
    connection_t            m_conn_type;

public:
    /***********************************************************************************************
    *
    * @brief   Establishes one-way connection from the first node to the second in adjacency collection.
    *
    * @param[in]  node_index1: index of node in the collection that should be connected with another.
    * @param[in]  node_index2: index of another node in the collection that should be connected with
    *                          the node defined by the first argument 'node_index1'.
    *
    ***********************************************************************************************/
    virtual void set_connection(const size_t node_index1, const size_t node_index2) = 0;
    
    /***********************************************************************************************
    *
    * @brief   Establishes one-way connection from the first node to the second in adjacency collection
    *          in case of zero state of connection and resets connection (remove it) in case of zero state.
    *
    * @param[in]  node_index1: index of node in the collection whose connection should be updated with another.
    * @param[in]  node_index2: index of another node in the collection.
    * @param[in]  state_connection: connection state from the first node to the second.
    *
    ***********************************************************************************************/
    virtual void update_connection(const size_t node_index1, const size_t node_index2, const TypeNode state_connection) = 0;

    /***********************************************************************************************
    *
    * @brief   Returns value of connection that denotes weight of connection, if there is no connection
    *          from the first node to the second then null value is returned.
    *
    * @param[in]  node_index1: index of node in the collection.
    * @param[in]  node_index2: index of another node in the collection.
    *
    ***********************************************************************************************/
    virtual TypeNode get_connection(const size_t node_index1, const size_t node_index2) const = 0;

    /***********************************************************************************************
    *
    * @brief   Returns vector of indexes of neighbors of specified node in line with adjacency collection.
    *
    * @param[in]  node_index: index of node in the collection.
    * @param[out] node_neighbors: vector of indexes of neighbors of specified node.
    *
    ***********************************************************************************************/
    virtual void get_neighbors(const size_t node_index, std::vector<size_t> & node_neighbors) const = 0;
};

#endif