
// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    merge_sort(0, pair_count - 1, pairs);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

// Merge Sort
void merge_sort(int start, int end, pair s[])
{
    if (end <= 1)
    {
        return;
    }

    int half = (pair_count - 1) / 2;

    merge_sort(start, half, s);
    merge_sort(half + 1, pair_count - 1, s);

    int left = start;
    int right = half + 1;
    pair sorted[pair_count];

    for (int i = start; i <= end; i++)
    {
        if (left == half + 1)
        {
            sorted[i] = s[right];
            right++;
        }
        else if (right == end + 1)
        {
            sorted[i] = s[left];
            left++;
        }
        else if (s[left] < s[right])
        {
            sorted[i] = s[left];
            left++;
        }
        else
        {
            sorted[i] = s[right];
            right++;
        }
    }

    for (int j = start; j <= end; j++)
    {
        s[j] = sorted[j];
    }
}

