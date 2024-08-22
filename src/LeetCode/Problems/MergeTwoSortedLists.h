// The solution for a LeetCode problem:
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem21
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

    class MergeTwoSortedLists
    {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
        {
            if (!list1) {
                return list2;
            }

            if (!list2) {
                return list1;
            }

            ListNode* nodeLeft = list1;
            ListNode* nodeRight = list2;

            // initializing result list with head
            ListNode* head = nullptr;

            if (nodeLeft->val < nodeRight->val) {
                head = nodeLeft;
                nodeLeft = nodeLeft->next;
            }
            else {
                head = nodeRight;
                nodeRight = nodeRight->next;
            }

            ListNode* node = head;

            // merging lists to head list
            while (nodeLeft && nodeRight) {
                if (nodeLeft->val < nodeRight->val) {
                    node->next = nodeLeft;
                    nodeLeft = nodeLeft->next;
                }
                else {
                    node->next = nodeRight;
                    nodeRight = nodeRight->next;
                }
                node = node->next;
            }

            // grabbing rest of the lists
            if (nodeLeft) {
                node->next = nodeLeft;
            }
            else {
                node->next = nodeRight;
            }

            return head;
        }
    };


    class MergeTwoSortedListsRunner : public ISolutionRunner
    {
        using LinkedList = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<MergeTwoSortedLists> solution = std::make_unique<MergeTwoSortedLists>();

            std::vector<std::pair<LinkedList, LinkedList>> linkedLists = {
                { { 1, 2, 4 }, { 1, 3, 4 } },
                { {}, { 0 } },
                { {}, {} },
            };

            for (const auto& [list1, list2] : linkedLists) {
                auto head1 = createLinkedList(list1);
                auto head2 = createLinkedList(list2);

                printLinkedList(head1, "Linked List 1: ");
                printLinkedList(head2, "Linked List 2: ");

                auto head = solution->mergeTwoLists(head1, head2);
                printLinkedList(head, "Merged List: ");

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

    REGISTER_SOLUTION_RUNNER("MergeTwoSortedLists", MergeTwoSortedListsRunner)
}
