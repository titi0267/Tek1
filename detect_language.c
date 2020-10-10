/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-lilou.stoll-metz
** File description:
** detect_language
*/

int calc_french(float *freq)
{
    float french[] = {7.63, 14.71, 0.73, 5.79, 1.36, 7.24, 6.31};
    float score = 0;

    for (int j = 0; j < 7; j += 1) {
        if (freq[j] - french[j] >= 0)
            score += freq[j] - french[j];
        else
            score += (freq[j] - french[j]) * -1;
    }
    return (score);
}

int calc_english(float *freq)
{
    float english[] = {8.16, 12.70, 6.09, 7.50, 0.09, 9.05, 2.75};
    float score = 0;

    for (int j = 0; j < 7; j += 1) {
        if (freq[j] - english[j] >= 0)
            score += freq[j] - english[j];
        else
            score += (freq[j] - english[j]) * -1;
    }
    return (score);
}

int calc_german(float *freq)
{
    float german[] = {6.51, 16.39, 4.57, 2.59, 0.01, 6.15, 4.16};
    float score = 0;

    for (int j = 0; j < 7; j += 1) {
        if (freq[j] - german[j] >= 0)
            score += freq[j] - german[j];
        else
            score += (freq[j] - german[j]) * -1;
    }
    return (score);

}

int calc_spanish(float *freq)
{
    float spanish[] = {11.52, 12.18, 0.70, 8.68, 0.87, 4.63, 2.92};
    float score = 0;

    for (int j = 0; j < 7; j += 1) {
        if (freq[j] - spanish[j] >= 0)
            score += freq[j] - spanish[j];
        else
            score += (freq[j] - spanish[j]) * -1;
    }
    return (score);
}

char *detect_language(char *str)
{
    float freq[7];
    char letters[] = "aehoqtu\0";
    for (int i = 0; letters[i] != '\0'; i += 1) {
        freq[i] = find_frequency(str, letters[i]);
    }
    int fr = calc_french(freq);
    int eng = calc_english(freq);
    int ger = calc_german(freq);
    int span = calc_spanish(freq);

    if (fr <= eng && fr <= ger && fr <= span)
        return("French");
    if (eng <= fr && eng <= ger && eng <= span)
        return("English");
    if (ger <= eng && ger <= fr && ger <= span)
        return("German");
    if (span <= eng && span <= ger && span <= fr)
        return("Spanish");
}