class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
            // Step 1: Build the adjacency list representation of the graph
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(numCourses, 0);

    // Populate the adjacency list and calculate the in-degree of each course
    for (const auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int prerequisiteCourse = prerequisite[1];
        graph[prerequisiteCourse].push_back(course);
        indegree[course]++;
    }

    // Step 2: Perform BFS
    queue<int> q;

    // Push courses with in-degree 0 into the queue
    for (int course = 0; course < numCourses; ++course) {
        if (indegree[course] == 0) {
            q.push(course);
        }
    }

    int count = 0;  // Counter for number of finished courses

    while (!q.empty()) {
        int currentCourse = q.front();
        q.pop();
        count++;

        // Decrement the in-degree of adjacent courses
        for (int course : graph[currentCourse]) {
            indegree[course]--;
            if (indegree[course] == 0) {
                q.push(course);
            }
        }
    }

    // Step 3: Check if all courses have been finished
    return count == numCourses;
    }
};