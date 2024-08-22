// The solution for a LeetCode problem:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem83
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

    class RemoveDuplicatesFromSortedList
    {
    public:
        ListNode* deleteDuplicates(ListNode* head)
        {
            if (!head) {
                return head;
            }

            ListNode* node = head;

            while (node && node->next) {
                if (node->val == node->next->val) {
                    ListNode* next = node->next->next;
                    delete node->next;
                    node->next = next;
                }
                else {
                    node = node->next;
                }
            }
            
            return head;
        }
    };


    class RemoveDuplicatesFromSortedListRunner : public ISolutionRunner
    {
        using LinkedList = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<RemoveDuplicatesFromSortedList> solution = std::make_unique<RemoveDuplicatesFromSortedList>();

            std::vector<LinkedList> linkedLists = {
                { 1, 1, 2 },
                { 1, 1, 2, 3, 3 },
                { 1, 1, 2, 2, 2, 3 },
                { 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 7, 8, 9, 9 },
                {},
            };

            for (const auto& linkedList : linkedLists) {
                auto head = createLinkedList(linkedList);

                printLinkedList(head, "Linked List: ");
                head = solution->deleteDuplicates(head);
                printLinkedList(head, "Linked List with duplicates removed: ");

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
            ListNode* prevNode = head;
            ListNode* node = head ? head->next : nullptr;

            while (prevNode) {
                delete prevNode;
                prevNode = node;
                node = (node && node->next) ? node->next : nullptr;
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("RemoveDuplicatesFromSortedList", RemoveDuplicatesFromSortedListRunner)
}
