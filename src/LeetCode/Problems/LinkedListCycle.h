// The solution for a LeetCode problem:
// https://leetcode.com/problems/linked-list-cycle/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem141
{
    // problem list struct
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class LinkedListCycleTwoPointers
    {
    public:
        bool hasCycle(ListNode* head)
        {
            if (head == nullptr || head->next == nullptr) {
                return false;
            }

            ListNode* slowNode = head;
            ListNode* fastNode = head;

            while (slowNode && fastNode)
            {
                slowNode = slowNode->next;
                fastNode = fastNode->next;
                if (fastNode) {
                    fastNode = fastNode->next;
                }

                if (fastNode == slowNode) {
                    break;
                }
            }

            return slowNode == fastNode;
        }
    };

    class LinkedListCycleHashMap
    {
    public:
        bool hasCycle(ListNode* head)
        {
            ListNode* node = head;
            std::unordered_set<ListNode*> _nodes;
            while (node) {
                if (_nodes.count(node) > 0) {
                    return true;
                }

                _nodes.insert(node);

                node = (node->next) ? node->next : nullptr;
            }
            return false;
        }
    };

    using LinkedList = std::vector<int>;

    struct LinkedListTest
    {
        LinkedList nodesValues;
        std::pair<int, int> cycledNodes;
    };

    class LinkedListCycleRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<LinkedListCycleHashMap> solution = std::make_unique<LinkedListCycleHashMap>();

            constexpr auto maxInt = std::numeric_limits<int>::max();

            std::vector<LinkedListTest> linkedLists = {
                { { 3, 2, 0, -4 }, { -4, 2 } },
                { { 3, 2, 0, -4 }, { maxInt, maxInt }},
                { { 1, 2 }, { 2, 1 } },
                { { 1 }, { maxInt, maxInt } }
            };

            for (const auto& linkedList : linkedLists) {
                ListNode* cycleFirst = nullptr;
                ListNode* cycleSecond = nullptr;

                ListNode* head = nullptr;
                ListNode* prevNode = nullptr;

                for (size_t i = 0; i < linkedList.nodesValues.size(); ++i) {
                    ListNode* node = new ListNode(linkedList.nodesValues[i]);
                    if (i == 0) {
                        prevNode = head = node;
                    }

                    if (i + 1 == linkedList.nodesValues.size()) {
                        node->next = nullptr;
                    }

                    if (node->val == linkedList.cycledNodes.first) {
                        cycleFirst = node;
                    }
                    if (node->val == linkedList.cycledNodes.second) {
                        cycleSecond = node;
                    }

                    if (prevNode != node) {
                        prevNode->next = node;
                    }

                    prevNode = node;
                }

                if (cycleFirst && cycleSecond) {
                    cycleFirst->next = cycleSecond;
                }

                std::cout << "\n" << "Linked List: ";

                ListNode* node = head;
                while (node) {
                    std::cout << node->val << " ";
                    node = node->next;
                    if (cycleFirst && node == cycleFirst) {
                        std::cout << node->val << " ";
                        break;
                    }
                }

                std::cout << "\n" << "Linked List Cycled: " << (solution->hasCycle(head) ? "has cycle" : "no cycle");

                prevNode = head;
                node = head ? head->next : nullptr;

                while (prevNode) {
                    delete prevNode;
                    prevNode = node;
                    if (node && node->next && node->next == cycleSecond) {
                        node = nullptr;
                    }
                    node = (node && node->next) ? node->next : nullptr;
                }

                std::cout << "\n";
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("LinkedListCycle", LinkedListCycleRunner)
}
