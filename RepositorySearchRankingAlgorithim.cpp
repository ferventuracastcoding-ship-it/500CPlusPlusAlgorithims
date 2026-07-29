#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Repo
{
    string name;
    int stars;
    int forks;
    int commitsLastMonth;
};

double score(const Repo& r)
{
    return r.stars * 0.4 +
           r.forks * 0.3 +
           r.commitsLastMonth * 2.0;
}

int main()
{
    vector<Repo> repos =
    {
        {"Compiler", 18000, 3500, 120},
        {"GameEngine", 12000, 2500, 300},
        {"AIFramework", 25000, 6000, 200}
    };

    sort(repos.begin(), repos.end(),
        [](const Repo& a, const Repo& b)
        {
            return score(a) > score(b);
        });

    for (const auto& repo : repos)
    {
        cout << repo.name
             << " Score: "
             << score(repo)
             << endl;
    }
}
