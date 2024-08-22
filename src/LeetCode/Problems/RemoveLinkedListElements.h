// The solution for a LeetCode problem:
// https://leetcode.com/problems/remove-linked-list-elements/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem203
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

    class RemoveLinkedListElements
    {
    public:
        ListNode* removeElements(ListNode* head, int val)
        {
            if (!head) {
                return nullptr;
            }

            ListNode* node = head;
            ListNode* prev = node;

            while (node) {
                if (node->val == val) {
                    ListNode* next = node->next;
                    if (prev != node) {
                        prev->next = next;
                    }
                    else {
                        prev = next;
                    }

                    if (head == node) {
                        head = next;
                    }

                    delete node;
                    node = next;
                }
                else {
                    prev = node;
                    node = node->next ? node->next : nullptr;
                }
            }

            return head;
        }
    };

    using LinkedList = std::vector<int>;

    struct LinkedListTestInfo
    {
        LinkedList linkedList;
        int value;
    };

    class RemoveLinkedListElementsRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<RemoveLinkedListElements> solution = std::make_unique<RemoveLinkedListElements>();

            std::vector<LinkedListTestInfo> lists = {
                { { 1, 2, 6, 3, 4, 5, 6 }, 1 },
                { { 7, 7, 7, 7 }, 7 },
                { { 1, 2, 2, 1 }, 2 },
                { {}, 1 },
            };

            for (const auto& list : lists) {
                auto head = createLinkedList(list.linkedList);

                printLinkedList(head, "Linked List: ");
                head = solution->removeElements(head, list.value);
                printLinkedList(head, "Linked List after remove: ");

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

    REGISTER_SOLUTION_RUNNER("RemoveLinkedListElements", RemoveLinkedListElementsRunner)
}
