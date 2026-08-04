// Last updated: 8/4/2026, 12:22:22 PM
long long calculateScore(char** instructions, int instructionsSize, int* values, int valuesSize) {
    bool* visited =(bool*)calloc(instructionsSize, sizeof(bool));
    long long score=0;
    int i=0;
    while(i>=0&&i<instructionsSize&&!visited[i]){
        visited[i]=true;
        if(strcmp(instructions[i], "add")==0){
            score += values[i];
            i++;
        }
        else if(strcmp(instructions[i], "jump")==0){
            i += values[i];
        }
    }
    free(visited);
    return score;
}