#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph equality and inequality")
{
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 1, 0}};
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 1, 1}};

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    // Check equality
    CHECK(g1 == g1);
    CHECK_FALSE(g1 == g2);
    CHECK_FALSE(g1 == g3);

    // Check inequality
    CHECK_FALSE(g1 != g1);
    CHECK(g1 != g2);
    CHECK(g1 != g3);
}

TEST_CASE("Test graph addition and subtraction")
{
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 1, 0}};

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    // Check addition
    ariel::Graph g_add_expected;
    vector<vector<int>> add_expected = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 2, 0}};
    g_add_expected.loadGraph(add_expected);
    CHECK((g1+g2) == g_add_expected);
    

    // Check subtraction
    ariel::Graph g_sub_expected;
    vector<vector<int>> sub_expected = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, 0, 0}};
    g_sub_expected.loadGraph(sub_expected);
    
    CHECK((g1-g2) == g_sub_expected);
}

TEST_CASE("Test graph multiplication by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    // Check multiplication by scalar
    ariel::Graph g_mult_expected;
    vector<vector<int>> mult_expected = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g_mult_expected.loadGraph(mult_expected);
    CHECK(g1.multByInt(2) == g_mult_expected);
}

TEST_CASE("Test unary operations on graphs")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    // Check unary plus operation
    CHECK(+g1 == g1);

    // Check unary minus operation
    ariel::Graph g_neg_expected;
    vector<vector<int>> neg_expected = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    g_neg_expected.loadGraph(neg_expected);
    CHECK(-g1 == g_neg_expected);

    // Check pre-increment and pre-decrement operations
    ariel::Graph g_preinc_expected;
    vector<vector<int>> preinc_expected = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}};
    g_preinc_expected.loadGraph(preinc_expected);
    CHECK((++g1) == g_preinc_expected);

    ariel::Graph g_predec_expected;
    vector<vector<int>> predec_expected = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g_predec_expected.loadGraph(predec_expected);
    CHECK((--g1) == g_predec_expected);
}

TEST_CASE("Test graph comparison operators")
{
    ariel::Graph g1, g2, g3, g4;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 1, 0}};
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 1, 0}};
    vector<vector<int>> graph4 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);
    g4.loadGraph(graph4);

    // Check greater than, greater than or equal to, less than, and less than or equal to
    CHECK_FALSE(g2 > g1);
    CHECK_FALSE(g2 >= g1);
    CHECK(g3 >= g2);
    CHECK_FALSE(g2 < g4);
    CHECK(g2 <= g3);
    CHECK(g1 < g3);
    CHECK_FALSE(g1 <= g3);
}
