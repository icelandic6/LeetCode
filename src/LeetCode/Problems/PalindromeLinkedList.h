// The solution for a LeetCode problem:
// https://leetcode.com/problems/palindrome-linked-list/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem234
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

    class PalindromeLinkedList
    {
    public:
        bool isPalindrome(ListNode* head)
        {
            if (!head) {
                return false;
            }

            ListNode* slow = head;
            ListNode* fast = head;

            // looking for middle
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next ? fast->next->next : fast->next;
            }

            ListNode* prev = nullptr;
            ListNode* next = slow;
            ListNode* node = slow;

            // reversing second half of the list
            while (node) {
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }

            ListNode* left = head;
            ListNode* right = prev;

            while (left && right) {
                if (left->val != right->val) {
                    return false;
                }

                left = left->next ? left->next : nullptr;
                right = right->next ? right->next : nullptr;
            }

            return true;
        }
    };

    class PalindromeLinkedListRecursive
    {
    public:
        bool isPalindrome(ListNode* head)
        {
            if (!head) {
                return false;
            }

            currentNode = head;
            return checkIsNodePalindrome(head);
        }

        bool checkIsNodePalindrome(ListNode* head)
        {
            if (head == nullptr) {
                return true;
            }

            bool isPalindrome = checkIsNodePalindrome(head->next) && (currentNode->val == head->val);

            currentNode = currentNode->next;

            return isPalindrome;
        }

    private:
        ListNode* currentNode;
    };

    class PalindromeLinkedListRunner : public ISolutionRunner
    {
        using LinkedList = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<PalindromeLinkedList> solution = std::make_unique<PalindromeLinkedList>();

            std::vector<LinkedList> linkedLists = {
                { 1, 2, 3, 3, 2, 1 },
                { 1, 2 },
                { 1, 2, 3, 3, 2 },
                { 1, 2, 3, 2, 1 },
                { 1 },
                { 0, 0 },
                {},
            };

            for (const auto& linkedList : linkedLists) {
                auto head = createLinkedList(linkedList);

                printLinkedList(head);

                std::cout << "\n" << "Is Palindrome: " << std::boolalpha << solution->isPalindrome(head);

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

    REGISTER_SOLUTION_RUNNER("PalindromeLinkedList", PalindromeLinkedListRunner)
}
