#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define STUDENT_COUNT 50
#define SUBJECT_COUNT 3

// 科目名称
const char* subjects[] = {"语文", "数学", "英语"};

// 学生结构体
struct Student {
    char name[20];
    float scores[SUBJECT_COUNT];
    float max_score;
    float min_score;
    float avg_score;
};

// 班级统计结构体
struct ClassStats {
    float max_score;
    float min_score;
    float avg_score;
    float median;
};

// 比较函数用于排序
int compare(const void* a, const void* b) {
    float diff = *(float*)a - *(float*)b;
    return (diff > 0) - (diff < 0);
}

void calculate_class_stats(float scores[], int count, struct ClassStats* stats) {
    qsort(scores, count, sizeof(float), compare);
    
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    
    stats->max_score = scores[count - 1];
    stats->min_score = scores[0];
    stats->avg_score = total / count;
    stats->median = (scores[count / 2] + scores[(count - 1) / 2]) / 2;
}

int main() {
    SetConsoleOutputCP(65001);  // 设置控制台输出为UTF-8编码
    
    // 初始化学生数据
    struct Student students[STUDENT_COUNT];
    float subject_scores[SUBJECT_COUNT][STUDENT_COUNT];
    struct ClassStats class_stats[SUBJECT_COUNT];
    
    // 生成随机成绩
    srand(2025);
    for (int i = 0; i < STUDENT_COUNT; i++) {
        sprintf(students[i].name, "学生%02d", i+1);
        
        students[i].max_score = 0;
        students[i].min_score = 100;
        float total = 0;
        
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            students[i].scores[j] = 60 + rand() % 41; // 60-100分
            subject_scores[j][i] = students[i].scores[j];
            
            if (students[i].scores[j] > students[i].max_score) {
                students[i].max_score = students[i].scores[j];
            }
            if (students[i].scores[j] < students[i].min_score) {
                students[i].min_score = students[i].scores[j];
            }
            total += students[i].scores[j];
        }
        students[i].avg_score = total / SUBJECT_COUNT;
    }
    
    // 计算每个科目的统计数据
    for (int j = 0; j < SUBJECT_COUNT; j++) {
        calculate_class_stats(subject_scores[j], STUDENT_COUNT, &class_stats[j]);
    }
    
    // 输出结果
    printf("班级成绩统计报告\n");
    printf("================\n");
    
    // 输出每个学生的成绩
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("\n%s 的成绩：\n", students[i].name);
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            printf("  %s: %.1f\n", subjects[j], students[i].scores[j]);
        }
        printf("  最高分: %.1f\n", students[i].max_score);
        printf("  最低分: %.1f\n", students[i].min_score);
        printf("  平均分: %.1f\n", students[i].avg_score);
    }
    
    // 输出每个科目的统计数据
    for (int j = 0; j < SUBJECT_COUNT; j++) {
        printf("\n%s 科目统计：\n", subjects[j]);
        printf("  最高分: %.1f\n", class_stats[j].max_score);
        printf("  最低分: %.1f\n", class_stats[j].min_score);
        printf("  平均分: %.1f\n", class_stats[j].avg_score);
        printf("  中位数: %.1f\n", class_stats[j].median);
    }
    
    return 0;
}