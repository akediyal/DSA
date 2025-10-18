class ListNode {
public:
  int key, val;
  ListNode *next;
  ListNode *prev;

  ListNode() {
    key = val = -1;
    next = prev = nullptr;
  }

  ListNode(int k, int value) {
    key = k;
    val = value;
    next = prev = nullptr;
  }
};

class LRUCache {
private:
  map<int, ListNode *> mp;
  int cap;
  ListNode *head;
  ListNode *tail;

  void deleteNode(ListNode *node) {
    ListNode *prev_node = node->prev;
    ListNode *next_node = node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
  }

  void insertAfterHead(ListNode *node) {
    ListNode *next_node = head->next;
    head->next = node;
    node->prev = head;
    next_node->prev = node;
    node->next = next_node;
  }

public:
  LRUCache(int capacity) {
    cap = capacity;
    mp.clear();

    head = new ListNode();
    tail = new ListNode();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key_) {
    if (mp.find(key_) == mp.end()) {
      return -1;
    }

    ListNode *node = mp[key_];
    int val = node->val;

    deleteNode(node);
    insertAfterHead(node);

    return val;
  }

  void put(int key_, int value) {
    if (mp.find(key_) != mp.end()) {
      ListNode *node = mp[key_];
      node->val = value;

      deleteNode(node);
      insertAfterHead(node);
    }

    else {
      if (mp.size() == cap) {
        ListNode *node = tail->prev;
        mp.erase(node->key);
        deleteNode(node);
      }

      ListNode *new_node = new ListNode(key_, value);
      mp[key_] = new_node;
      insertAfterHead(new_node);
    }
  }
};
