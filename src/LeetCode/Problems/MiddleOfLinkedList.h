// The solution for a LeetCode problem:
// https://leetcode.com/problems/middle-of-the-linked-list/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem876
{
    // problem list struct
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class MiddleOfLinkedList
    {
    public:
        ListNode* middleNode(ListNode* head)
        {
            if (!head) {
                return nullptr;
            }

            auto middleNode = head;
            auto node = head;
            int size = 1;

            while (node) {
                if ((size + 1) % 2 != 0) {
                    middleNode = middleNode->next;
                }

                ++size;
                node = node->next ? node->next : nullptr;
            }

            return middleNode;
        }
    };


    class MiddleOfLinkedListTwoPointers
    {
    public:
        ListNode* middleNode(ListNode* head)
        {
            if (!head) {
                return nullptr;
            }

            ListNode* slowNode = head;
            ListNode* fastNode = head;

            while (slowNode && fastNode) {
                slowNode = slowNode->next;
                fastNode = fastNode->next;
                if (fastNode) {
                    fastNode = fastNode->next;
                }
            }

            return slowNode;
        }
    };

    class MiddleOfLinkedListRunner : public ISolutionRunner
    {
        using LinkedList = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<MiddleOfLinkedListTwoPointers> solution = std::make_unique<MiddleOfLinkedListTwoPointers>();

            std::vector<LinkedList> linkedLists = {
                { 1, 2, 3, 4, 5 },
                { 1, 2, 3, 4, 5, 6 }
            };

            for (const auto& linkedList : linkedLists) {
                auto head = createLinkedList(linkedList);

                printLinkedList(head);

                auto middleNode = solution->middleNode(head);
                std::cout << "\n" << "Linked List Middle Node: " << (middleNode ? middleNode->val : -1);

                clearLinkedList(head);

                std::cout << "\n";
            }

            std::cout << "\n";
        }

        ListNode* createLinkedList(const LinkedList& linkedList)
        {
            ListNode* head = nullptr;
            ListNode* prevNode = nullptr;

            for (size_t i = 0; i < linkedList.size(); ++i) {
                ListNode* node = new ListNode(linkedList[i]);
                if (i == 0) {
                    prevNode = head = node;
                }

                if (i + 1 == linkedList.size()) {
                    node->next = nullptr;
                }

                if (prevNode != node) {
                    prevNode->next = node;
                }

                prevNode = node;
            }

            return head;
        }

        void printLinkedList(ListNode* head)
        {
            std::cout << "\n" << "Linked List: ";

            ListNode* node = head;

            while (node) {
                std::cout << node->val << " ";
                node = node->next;
            }
        }

        void clearLinkedList(ListNode* head)
        {
            std::cout << "\n" << "Deleting Linked List: ";

            ListNode* prevNode = head;
            ListNode* node = head ? head->next : nullptr;
            while (prevNode) {
                std::cout << prevNode->val << " ";
                delete prevNode;
                prevNode = node;
                node = (node && node->next) ? node->next : nullptr;
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("MiddleOfLinkedList", MiddleOfLinkedListRunner)
}
