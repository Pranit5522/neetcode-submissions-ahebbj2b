/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), comp);

        int maxRooms = 0;
        for(Interval interval: intervals) {
            while(!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }
            pq.push(interval.end);
            maxRooms = max(maxRooms, (int)pq.size());
        }

        return maxRooms;
    }
};
