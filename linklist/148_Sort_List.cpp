// 2022.08.02
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //利用自底向上的归并思想，每次先归并好其中一段，之后两段之间进行归并
        int n = 0;
        for(auto p = head; p ; p = p->next) n ++;

        auto dummy = new ListNode(-1); // 因为 head 可能会变，因为原始的 head->val 可能不是最小的，就会被移到后面
        dummy->next = head;

        // 要明白下面第1个和 第2个for循环是什么，第1个for循环是 纵向层与层之间的迭代，第2个for循环是 横向 每层 从左往右 每次 2i段遍历
        for(int i = 1; i < n; i *= 2 ){ //每次归并段的长度，每次长度依次为1,2,4,8...n/2
        //小于n是因为等于n时说明所有元素均归并完毕，大于n时同理
            auto cur = dummy; // 因为下面for循环第一次进入时(即每一层第一段头结点 是从第一个结点head开始的，这个第一个结点head也是会变的)，要保证 first = head, 所以这里要将 cur = dummy, 因为dummy->next =head, 能保证 first = cur->next = head 
            // 根据把链表头结点 索引当成0 或 1 有两种写法：写法一： j = 0; j + i < n;     写法二：j = 1; j + i <= n;
            for(int j = 0; j + i < n; j += 2 * i){//j代表每一段的开始，每次将两段有序段归并为一个大的有序段，故而每次+2i
            //必须保证每段中间序号是小于链表长度的，显然，如果大于表长，就没有元素可以归并了
                auto first = cur->next, second = first;//p表示2i段第一段的起始点，cur是上一排好序的2i链表段的尾结点（这个起始点会变，不能用p=head），q表示2i段第二段的起始点，之后开始归并即可
                for(int k = 0; k < i; k ++) second = second->next;

                //f,s用于计数第一段和第二段归并的节点个数，由于当链表长度非2的整数倍时表长会小于i,故而需要加上first && second的边界判断
                 int f = 0, s = 0;
                 while(f < i && s < i && first && second){  // 加 && second 是因为 第二段长度 可能不满 i
                // 这里可以不用 && first, 因为上面 j+i<=n 保证了，有第二段，所以第一段肯定存在 且 长度为i
                     if(first->val <= second->val) cur = cur->next = first,first = first->next,f ++; //等号的赋值顺序为从右到左，故而该句意思为
                     //cur->next = first,cur = cur->next,即将小的一点插入cur链表中
                     // 此处注意 归并排序 用 数组是这种形式，tmp[k ++ ] = first[i ++ ]，但是这里不能采用cur = first, cur = cur->next,这样就不对了，这是 链表实现归并排序 与数组实现归并排序不同之处，要注意,可以写成cur->next = first ，cur = first 
                     else cur = cur->next = second,second = second->next,s++;
                 }


                //归并排序基本套路
                 while(f < i && first) cur = cur->next = first,first = first->next,f ++; // 这里可以不加 && first，原理同上
                 while(s < i && second) cur = cur->next = second,second = second->next,s ++;  // 跳出循环时，second已经是 j+2i 下一2i链表段的新的头结点
                 cur->next = second; //记得把排好序的链表尾 链接 到 j+2i 下一2i链表 的表头，循环完毕后 second 为下一2i链表表头
            }
        } 
        return dummy->next;
    }
};