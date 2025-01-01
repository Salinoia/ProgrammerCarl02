
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList {
public:
    struct LinkedList{
        int val;
        LinkedList* next;
        LinkedList(int val) : val(val), next(nullptr){}
    };
    MyLinkedList() {
        _sentinel_node = new LinkedList(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index >= _size || index < 0){
            return -1;
        }
        LinkedList* current_node = _sentinel_node->next;
        while(index--){
            current_node = current_node->next;
        }
        return current_node->val;
    }
    
    void addAtHead(int val) {
        LinkedList* new_node = new LinkedList(val);
        new_node->next = _sentinel_node->next;
        _sentinel_node->next = new_node;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedList* new_node = new LinkedList(val);
        LinkedList* current_node = _sentinel_node;
        while(current_node->next != nullptr){
            current_node = current_node->next;
        }
        current_node->next = new_node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;// 大于链表长度，返回
        if(index < 0) index = 0;// 小于零，插入头结点
        // 其余情况引入虚拟头结点以后均可视为一致的处理逻辑
        LinkedList* new_node = new LinkedList(val);
        LinkedList* current_node = _sentinel_node;
        while(index--){
            current_node = current_node->next;
        }
        new_node->next = current_node->next;// 链表尾部nullptr也无所谓，就相当于插入在尾部了
        current_node->next = new_node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size){
            return;
        }
        LinkedList* current_node = _sentinel_node;
        while(index--){
            current_node = current_node->next;
        }
        LinkedList* temp_node = current_node->next;
        current_node->next = current_node->next->next;
        delete temp_node;
        _size--;
    }
    ~MyLinkedList(){
        LinkedList* current_node = _sentinel_node;
        while(current_node){
            LinkedList* temp_node = current_node;
            current_node = current_node->next;
            delete temp_node;
        }
    }
private:
    LinkedList* _sentinel_node;
    int _size;
};
