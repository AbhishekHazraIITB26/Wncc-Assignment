#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool hasMentor(unordered_map<string, vector<int>>& participants, const string& project, const string& rollNumber) {
    vector<int>& currentSkills = participants[rollNumber];
    for (auto& participant : participants) {
        if (participant.first != rollNumber) {
            vector<int>& otherSkills = participant.second;
            if (otherSkills == currentSkills) {
                if (participant.second > currentSkills) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    unordered_map<int, vector<int>> participants;
    unordered_set<int> joinedProjects; // To track projects already joined by a participant
    int N, M;
    cout << "Enter the number of participants: ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int rollNumber;
        vector<int> skillLevels(5);
        cout << "Enter participant's roll number followed by skill levels (HTML, Python, DSA, Java, SQL): ";
        cin >> rollNumber;
        for (int j = 0; j < 5; j++) {
            cin >> skillLevels[j];
        }
        participants[rollNumber] = skillLevels;
    }
    
    int completedProjects = 0;
    cout << "Enter the number of projects: ";
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        string projectName;
        vector<int> skillLevelsRequired(5);
        cout << "Enter project name followed by required skill levels (HTML, Python, DSA, Java, SQL): ";
        cin >> projectName;
        for (int j = 0; j < 5; j++) {
            cin >> skillLevelsRequired[j];
        }
        bool projectCompleted = true;
        
        for (int j = 0; j < 5; j++) {
            int skillRequired = skillLevelsRequired[j];
            if (skillRequired == 0) {
                continue;
            }
            bool skillFound = false;
            
            for (auto& participant : participants) {
                int rollNumber = participant.first;
                // Skip participant if already joined a project
                if (joinedProjects.count(rollNumber) > 0)
                    continue;
                
                if (participant.second[j] >= skillRequired) {
                    skillFound = true;
                    joinedProjects.insert(rollNumber); // Mark participant as joined
                    break;
                } else if (participant.second[j] == skillRequired - 1) {
                    if (hasMentor(participants, projectName, rollNumber)) {
                        skillFound = true;
                        joinedProjects.insert(rollNumber); // Mark participant as joined
                        break;
                    }
                }
            }
            
            if (!skillFound) {
                projectCompleted = false;
                break;
            }
        }
        
        if (projectCompleted) {
            completedProjects++;
        }
    }
    
    cout << "Number of completed projects: " << completedProjects << endl;
    
    return 0;
}
