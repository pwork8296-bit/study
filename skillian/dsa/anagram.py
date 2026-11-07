
anagram = "anagram"
tanagram = "tanagram"

dic1 = {}

for x in range(len(anagram)):
    if(dic1.get(anagram[x])):
        dic1[anagram[x]] += 1
    else:
        dic1[anagram[x]] = 1

for x in range(len(tanagram)):
    if(dic1.get(tanagram[x])):
        dic1[tanagram[x]] -= 1
    else:
        dic1[tanagram[x]] = -1

    
print(dic1)



def anagram_arr_count():
    strArr = ['eat','tan','nat','bat','tab','ate']