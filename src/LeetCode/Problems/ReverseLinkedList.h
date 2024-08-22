// The solution for a LeetCode problem:
// https://leetcode.com/problems/reverse-linked-list/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem206
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

    class ReverseLinkedList
    {
    public:
        ListNode* reverseList(ListNode* head)
        {
            ListNode* node = head;
            ListNode* reverseNode = head;
            ListNode* nextNode = nullptr;

            while (node) {
                nextNode = node->next;
                node->next = (node != head) ? reverseNode : nullptr;
                reverseNode = node;
                node = nextNode;
            }

            return reverseNode;
        }
    };

    class ReverseLinkedListRunner : public ISolutionRunner
    {
        using LinkedList = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<ReverseLinkedList> solution = std::make_unique<ReverseLinkedList>();

            std::vector<LinkedList> linkedLists = {
                { 1, 2, 3, 4, 5 },
                { 1, 2 },
                {}
            };

            for (const auto& linkedList : linkedLists) {
                auto head = createLinkedList(linkedList);

                printLinkedList(head, "Linked List: ");

                auto reversedHead = solution->reverseList(head);

                printLinkedList(reversedHead, "Reversed Linked List: ");

                clearLinkedList(head, reversedHead);

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

        void printLinkedList(ListNode* head, const std::string& title)
        {
            std::cout << "\n" << title;

            ListNode* node = head;

            if (!node) {
                std::cout << "-";
            }

            while (node) {
                std::cout << node->val << " ";
                node = node->next;
            }
        }

        void clearLinkedList(ListNode* head, ListNode* reversedHead)
        {
            std::cout << "\n" << "Deleting Linked List: ";

            ListNode* prevNode = reversedHead ? reversedHead : head;
            ListNode* node = reversedHead ? reversedHead->next : nullptr;
            while (prevNode) {
                std::cout << prevNode->val << " ";
                delete prevNode;
                prevNode = node;
                node = (node && node->next) ? node->next : nullptr;
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("ReverseLinkedList", ReverseLinkedListRunner)
}
