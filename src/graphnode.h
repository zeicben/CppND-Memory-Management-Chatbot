#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    /// MODIFIED - vector of *GraphEdge into vector of unique_ptr holding GraphEdge objects
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;
    // std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    /// NO NEED TO MODIFY - parent edges were not owned by this class; 
    /// they will remain stored as a vector of edges
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    /// MODIFIED - _chatBot became object, not raw pointer
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    /// MODIFIED - receive a unique_ptr as parameter, instead of raw pointer
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    /// MODIFIED - chatBot became object, not raw pointer
    void MoveChatbotHere(ChatBot chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */