#퀵 정렬 코드
def quicksort(arr):
    if len(arr) <= 1: # 배열 <= 1 → 반환(종료)
        return arr
    pivot = arr[-1] # 피벗 = -1 (리스트 마지막)
    left = [x for x in arr[:-1] if x < pivot] # 값 < 피벗 → left
    right = [x for x in arr[:-1] if x >= pivot] # 값 >= 피벗 → right

    return quicksort(left) + [pivot] + quicksort(right) #left, right 추가 정렬 후 합쳐 반환(종료)

#삽입 정렬 코드
def insertion_sort(arr):
    completed = []
    for x in arr: #x가 들어갈 위치까지 Increment 후 삽입
        i = 0
        while i < len(completed) and completed[i] < x: # i < 정렬 완료된 배열 && 정렬 완료된 배열 < x → i 증가
            i += 1
        completed.insert(i, x) # 정렬 완료된 배열 i번째에 x 삽입

    return completed #정렬 완료 후 반환(종료)

#input 파일 배열로 불러오기
input_array = []
with open('input_array.dat', 'r') as in_arr:
    for line in in_arr:
        input_array.append(line.strip())

#정렬 전 코드 출력
print("┌─────────────┬───────────────────────────────┐")
print("│ input_array │ input_array.dat 불러오기 완료 │")
print("└─────────────┴───────────────────────────────┘")
print(input_array, "\n")

# 삽입 정렬 <= 20 < 퀵 정렬 (안내 출력 포함)
print("┌─────────────┬───────────────────────┐")

if len(input_array) <= 20:
    sorted_array = insertion_sort(input_array)
    print("│ input_array │ 삽입 정렬로 정렬 완료 │")

else:
    sorted_array = quicksort(input_array)
    print("│ input_array │ 퀵 정렬로 정렬 완료   │")

print("└─────────────┴───────────────────────┘")
print(sorted_array, "\n")

#output 파일 배열로 내보내기
with open('output_array.dat', 'w') as out_arr:
    for line in sorted_array:
        out_arr.write(f"{line}\n")

print("┌──────────────┬────────────────────────────┐")
print("│ output_array │ output_array.dat 저장 완료 │")
print("└──────────────┴────────────────────────────┘")