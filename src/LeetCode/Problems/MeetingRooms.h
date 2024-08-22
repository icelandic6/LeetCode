// The solution for a LeetCode problem:
// https://leetcode.com/problems/meeting-rooms

#include <vector>
#include <algorithm>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem252
{
    class MeetingRooms
    {
    public:
        bool canAttendMeetings(std::vector<std::vector<int>>& intervals)
        {
            if (intervals.size() < 2) {
                return true;
            }

            std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& l, const std::vector<int>& r) {
                return l[0] < r[0];
            });

            for (size_t i = 0; i < intervals.size() - 1; ++i) {
                if (intervals[i][1] > intervals[i + 1][0]) {
                    return false;
                }
            }

            return true;
        }
    };

    class MeetingRoomsRunner : public ISolutionRunner
    {
        using MeetingTimeIntervals = std::vector<int>;
        using MeetingTimeIntervalsArray = std::vector<MeetingTimeIntervals>;

    public:
        void run() override
        {
            std::unique_ptr<MeetingRooms> solution = std::make_unique<MeetingRooms>();

            std::vector<MeetingTimeIntervalsArray> intervalsCases = {
                { { 0, 30 }, { 5, 10 }, { 15, 20 } },
                { { 7, 10 }, { 2, 4 } },
            };

            for (auto& intervals : intervalsCases) {
                // printing intervals
                std::cout << "\n" << "Meetings Intervals: ";
                for (const auto& interval : intervals) {
                    if (interval.size() == 2) {
                        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
                    }
                    else {
                        std::cout << "Wrong meeting interval format!";
                    }
                }

                // calculating
                std::cout << "\n" << "Can attend: " << std::boolalpha << solution->canAttendMeetings(intervals) << "\n\n";
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("MeetingRooms", MeetingRoomsRunner)
}
