
from collections import OrderedDict

absolute_path = r'D:\__Alexzander_files__\__computer_science__\python_stuff\andrew_packages\programming_problems\reply_challenge'

class TestCase:
    def __init__(self, index, total_teams, total_logs, teams_stats_list):
        self.index = index
        self.total_teams = total_teams
        self.total_logs = total_logs
        self.teams_stats_list = teams_stats_list

    def __str__(self):
        content = '=' * 50 + '\n'
        content += f'Test case[{self.index}] =>\n'
        content += f'\ttotal teams involved: {self.total_teams}\n'
        content += f'\ttotal logs read: {self.total_logs}\n'
        content += '\t' + '~' * 50 + '\n'
        content += f'\tTeams stats for this test case:\n'
        for ts in self.teams_stats_list:
            content += f'{ts}'
        content += '\n' + '=' * 50 + '\n'
        return content

class TeamStats:
    def __init__(self, timestamp, team_id, problem_id, input_id, scored):
        self.timestamp = timestamp
        self.team_id = team_id
        self.problem_id = problem_id
        self.input_id = input_id
        self.scored = scored

    def __str__(self):
        content = '\t\t' + '~' * 50 + '\n'
        content += f'\t\tTeam[{self.team_id}] with =>\n'
        content += f'\t\t\ttimestamp: {self.timestamp}\n'
        content += f'\t\t\tproblem id: {self.problem_id}\n'
        content += f'\t\t\tinput id: {self.input_id}\n'
        content += f'\t\t\tscored: {self.scored}\n'
        content += '\t\t' + '~' * 50 + '\n'
        return content

def ReadFromFile(filename: str):
    with open(filename, 'r', encoding='utf-8') as input_file:
        test_cases = list()
        T = int(input_file.readline()[0])

        T_index = 0
        teams_stats = list()
        line = tuple(map(int, input_file.readline().split()))
        if len(line) == 2:
            N, L = line
        while line:
            if len(line) == 5:
                timestamp, team_id, problem_id, input_id, scored = line
                teams_stats.append(TeamStats(timestamp, team_id, problem_id, input_id, scored))

            elif len(line) == 2:
                if teams_stats:
                    test_cases.append(TestCase(T_index, N, L, teams_stats))
                    teams_stats = list()
                    T_index += 1
                N, L = line
            line = tuple(map(int, input_file.readline().split()))

        T_index += 1
        test_cases.append(TestCase(T_index, N, L, teams_stats))
        return test_cases

def ComputeProblem(test_cases_list: list):
    test_cases_results = list()
    for testcase in test_cases_list:
        teams = OrderedDict()
        absent_teams = [1, 2, 3, 4, 5]
        for teamstats in testcase.teams_stats_list:
            # update the actual team
            id = teamstats.team_id
            if id in absent_teams:
                absent_teams.remove(id)
            if id in teams:
                if teamstats.scored == 1:
                    # we update the stats
                    teams[id]['score'] += teamstats.problem_id * 100 * teamstats.input_id
                    teams[id]['penalty_time'] += teamstats.timestamp
            else:
                teams[id] = OrderedDict()
                if teamstats.scored == 1:
                    teams[id]['score'] = teamstats.problem_id * 100 * teamstats.input_id
                    teams[id]['penalty_time'] = teamstats.timestamp
                else:
                    teams[id]['score'] = 0
                    teams[id]['penalty_time'] = 0

        for abst_team in absent_teams:
            teams[abst_team] = OrderedDict()
            teams[abst_team]['score'] = 0
            teams[abst_team]['penalty_time'] = 0

        test_cases_results.append(teams)
    return test_cases_results

def Tranform(final_results: list):
    results = list()
    for testcase_dict in final_results:
        testcase_result = list()
        for teamid in testcase_dict:
            new_format = OrderedDict()
            new_format['team'] = teamid
            new_format['score'] = testcase_dict[teamid]['score']
            new_format['penalty_time'] = testcase_dict[teamid]['penalty_time']
            testcase_result.append(new_format)
        results.append(testcase_result)
    return results

def DisplayTeamsResults(teams_dict: dict):
    for teamid in teams_dict:
        sc = teams_dict[teamid]["score"]
        pen = teams_dict[teamid]["penalty_time"]
        print(f'Team {teamid} with {sc} points and {pen} penalty time.')

def DisplayDictionaries(final_results: list):
    print('\n[')
    for testcase_dict in final_results:
        print('\t{')
        for teamid in testcase_dict:
            print(f'\t\t{teamid}: {dict(testcase_dict[teamid])}')
        print('\t}')
    print(']\n')

def DisplayResults(final_results: list):
    print('\n[')
    for testcase_list in final_results:
        print('\t[')
        for team_dict in testcase_list:
            print(f'\t\t{dict(team_dict)}')
        print('\t]')
    print(']\n')

def SortFinalResults(final_results: list):
    sorted_results = []
    for testcase_list in final_results:
        testcase_sorted = sorted(testcase_list, key=lambda dictionary: (-dictionary['score'], dictionary['penalty_time']))
        sorted_results.append(testcase_sorted)
    return sorted_results

def WriteInFile(final_results: list, absolute_path: str):
    with open(absolute_path, 'w', encoding='utf-8') as results_file:
        for index, testcase in enumerate(final_results):
            results_file.write(f'Case: #{index + 1}: ')
            for team in testcase:
                results_file.write(f'{team["team"]} ')
            results_file.write('\n')

if __name__ == '__main__':

    input_files_list = [
        '\input1.txt',
        '\input2.txt',
        '\input3.txt'
    ]

    for index, file in enumerate(input_files_list):
        test_cases = ReadFromFile(absolute_path + file)

        results = ComputeProblem(test_cases)
        results = Tranform(results)
        results = SortFinalResults(results)

        DisplayResults(results)
        WriteInFile(results, absolute_path + f'\input{index + 1}_results.txt')

        print('=' * 100)