#pragma once

#include <base.hpp>

namespace hny {

    template<typename T>
    class _list {
        private:
            struct _list__list__node {
                T data;
                _list__list__node* next;
            };

            _list__list__node* head;
            int size;

        public:

            _list() : head(nullptr), size(0) {};

            void append(T value) {
                _list__list__node* new_list__list__node = new _list__list__node();
                new_list__list__node->data = value;
                new_list__list__node->next = nullptr;

                if (head == nullptr)
                    head = new_list__list__node;
                else {
                    _list__list__node* current = head;
                    while (current->next != nullptr)
                        current = current->next;
                    current->next = new_list__list__node;
                }

                size++;
            }

            explicit operator bool() const {
                return this->head != nullptr;
            };

            int length() const {
                return size;
            }

            T __getitem(_uint index) const {
                if (index >= 0 && index < size) {
                    _list__list__node* current = head;
                    for (int i = 0; i < index.__to_c(); ++i)
                        current = current->next;
                    return current->data;
                }
                
                rt::IndexError.raise("list index out of range");

                return T();
            }

            void __remitem(_uint index) {
                if (index >= 0 && index < size) {
                    _list__list__node* temp = head;
                    for (int i = 0; i < index.__to_c(); ++i)
                        temp = temp->next;

                    _list__list__node* prev = temp->prev;
                    _list__list__node* next = temp->next;

                    if (temp == head)
                        head = next;
                    else
                        prev->next = next;

                    if (next != nullptr)
                        next->prev = prev;

                    delete temp;
                    --size;

                } else rt::IndexError.raise("list index out of range");
            };
            
            T __setitem(_uint index, T value) const {
                if (index >= 0 && index < size) {
                    _list__list__node* current = head;
                    for (int i = 0; i < index.__to_c(); ++i)
                        current = current->next;
                    current->data = value;
                } else {
                    rt::IndexError.raise("list index out of range");
                }
            }
    };
};
