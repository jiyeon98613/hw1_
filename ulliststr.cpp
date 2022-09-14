#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/*my code*/

  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    
      Item* tracker = head_;
      size_t buf = (tracker->last-tracker->first);
      
      while(loc >= buf)
      {
        tracker = tracker->next;
        loc -= buf;
        buf = (tracker->last-tracker->first);
      }
      //get into the list node that have the target string

      return & tracker->val[tracker->first + loc];
    
  }
  
  /*
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val)
  {
    //std::cout<< "size:" << this->size()<< std::endl;
    ++size_;
    //case #1
    if(head_ == nullptr)                 //If there is no node at all.
    {
      //std::cout<< "at p_b if: make a new list" << std::endl;
      //set LL
      head_ = new Item();
      
      tail_ = head_;
      head_->last = 1;
      //set array
      head_->val[0] = val; 
      //std::cout<< head_->val[0] << std::endl;

      
      
    }
    else if(tail_->last == ARRSIZE)  //If the temp->last = 10; array가 꽉 찼을때
    {
      Item* temp = new Item();
      //std::cout<< "at p_b elif: full arr" << std::endl;
      //set array 

      temp->val[0] = val;          
      temp->first = 0;
      temp->last = 1;
      //set the LL
      tail_->next = temp;
      temp->prev = tail_;
      tail_ = tail_->next;
      
    }
    else                            // adding the element in the existing array; array에 공간이 남아있을 때
    {
      //std::cout<< "at p_b else" << std::endl;
      tail_->val[tail_->last] = val;
      ++(tail_->last);

    }
    
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back()
  {
    //std::cout<< "size:" << this->size()<< std::endl;
    if(head_ == NULL)
    {
      //std::cout<< "at pop_b wrong input" << std::endl;
      return;
      //what should I do here?
    }
    if(tail_->last == 1 && tail_ != head_) //여러 node중에 tail node를 지울 때
    {
      //std::cout<< "at pop_b if: deleting tail" << std::endl;
      Item* temp = tail_;
      temp->prev->next = nullptr;
      tail_ = tail_->prev;
      delete temp;
      
    }
    else if(size_ == 1) // 가장 마지막 남은 것일 때
    {
      //std::cout<< "at pop_b elif: deleting the last string" << std::endl;
      delete head_;
      head_ = nullptr, tail_ = nullptr;

    }
    else
    {
      //std::cout<< "at pop_b else" << std::endl;
      (tail_->val[tail_->last-1]).clear();
      --(tail_->last);

    }
    --size_;
    return;
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val)
  {
    //std::cout<< "size:" << this->size()<< std::endl;
    ++size_;
    //case #1
    if(head_ == nullptr)                 //If there is no node at all.
    {
      //std::cout<< "at p_f if: make a new list" << std::endl;
      //set LL
      head_ = new Item();
      tail_ = head_;
      head_->last = ARRSIZE;
      head_->first = ARRSIZE-1;
      head_->val[head_->first] = val;
      //--head_->first;

      
    }
    else if(head_->first == 0)       //If the head->first = 0 ;새 노드 추가해야 될 때
    {
      Item* temp = new Item();
      //std::cout<< "at p_f elif: add new node" << std::endl;
                      
      temp->first = ARRSIZE-1;
      temp->last = ARRSIZE;
      temp->val[temp->first] = val;
      //set the LL
      head_->prev = temp;
      temp->next = head_;
      head_ = head_->prev;
      
      
    }
    else                            // adding the element in the existing array; array에 공간 남아있을 때
    {
      //std::cout<< "at p_f else" << std::endl;
      --(head_->first);
      head_->val[head_->first] = val;
    }
    
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front()
  {
    //std::cout<< "size:" << this->size()<< std::endl;
    if(head_ == NULL)               //아무것도 없을 때
    {
      //std::cout<< "at pop_f wrong input" << std::endl;
      return;
    }
    //when we need to delete the head node and 
    //move on to the next node
  
    if(head_->first == ARRSIZE-1 && tail_ != head_)   //노드를 하나 삭제해야 할 때
    {  
      //std::cout<< "at pop_f if: deleting one node" << std::endl;
      Item* temp = head_;
      head_->next->prev = nullptr;
      head_ = head_->next;
      delete temp;
    }
    else if(size_ == 1) // 가장 마지막 남은 것일 때
    {
      //std::cout<< "at pop_f elif: deleing the last string" << std::endl;
      delete head_;
      head_ = nullptr, tail_ = nullptr;

    }
    else                            //그냥 현재 있는 ARRAY에서 하나 삭제할 때
    {
      //std::cout<< "at pop_f else" << std::endl;
      (head_->val[head_->first]).clear();
      ++(head_->first);
    }
    --size_;
    return;
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const
  {
    //std::cout<< "size:" << this->size()<<" ";
    return tail_->val[(tail_->last)-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const
  {
    //std::cout<< "size:" << this->size()<< " ";
    return head_->val[head_->first];
  }