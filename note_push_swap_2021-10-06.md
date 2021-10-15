# note_push_swap
Date: 2021-10-06

<hr>

## 内容

### 前回やったこと

想方向循環リストをint型の配列に直す。  
リストの中央値を求める  
中央値よりも小さいものをBのスタックに移動させる  

### 今回やること

メモリりーくしているので、それを治す  
アルゴリズム理論について調べる  

### メモ

#### 今日わかったこと

- ローカル変数は、関数が終了すると死んでしまう  
- 参照私をする場合は、関数同士の入れこの関係に注意が必要  
- mallocをすると関数が終了しても変数が死ぬことはないので、関数同士の入れこの関係に注意する必要はない  
→ これらのことから、mallocで構造体を動的に確保する必要がある  

#### 今日やったこと

- mallocで確保したint型の配列のfreeを忘れていて、memory leakになったので直した  
- クイックソート（分割統治法））の実装方法について考えた  

###### 分割倒置法の擬似コーディング


```
func_half_A_to_B();

void func_qick_sort()
{
	int n;
	int m;
	
	n = len(stack_B);
	if (n < 6)
		break ;
	B_to_A();  // mこ移動させる（中央値よりも大きいやつを。）
	func();
	rule_sort();
	B_to_A();  // Aの全部を一番下にくっつける  
	A_to_B();  // mこ移動させる
}
```

```python
#!/usr/bin/env python
# coding: utf-8

# In[452]:


stack_a = list(range(100)) # [0, 1, 2, ... 96, 97, 98, 99]
import random
random.shuffle(stack_a)
stack_b = []
stack_a


# In[453]:


import statistics

def half_A_to_B():
    
    median = statistics.median(stack_a)
    index_list = []
    i = 0
    while (i < len(stack_a)):
        if (stack_a[i] < median):
            stack_b.insert(0, stack_a[i])
            index_list.append(i)
        i += 1
    for i in sorted(index_list, reverse=True):
        stack_a.pop(i)


# In[454]:


def half_B_to_A():
    
    median = statistics.median(stack_b)
    index_list = []
    i = 0
    while (i < len(stack_b)):
        if (stack_b[i] > median):
            stack_a.insert(0, stack_b[i])
            index_list.append(i)
        i += 1
    for i in sorted(index_list, reverse=True):
        stack_b.pop(i)
    return len(index_list)


# In[455]:


def all_B_to_A():
    
    i = 0
    while (i < len(stack_b)):
            stack_a.append(stack_b[0])
            stack_b.pop(0)


# In[456]:


def count_A_to_B(count):
    i = 0
    
    while (i < count):
            stack_b.insert(0, stack_a[0])
            stack_a.pop(0)
            i += 1


# In[457]:


def quick_sort():
    stack_b_len = len(stack_b)
    count = 0

    if (stack_b_len < 6):
        return
    count = half_B_to_A()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    quick_sort()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    stack_b.sort()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    all_B_to_A()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    count_A_to_B(count)
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    quick_sort()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    stack_b.sort()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")
    
    all_B_to_A()
    
    print("-=-=-=-=-=-\n")
    print("stack_a: " + str(stack_a) + "\n")
    print("stack_b: " + str(stack_b) + "\n")
    print("-=-=-=-=-=-\n")


# In[458]:


half_A_to_B()
quick_sort()


# In[ ]:
```