#pragma once

#include <base.h>

namespace hny {

    template<typename T>
    class _list {
        private:
            struct __node {
                T data;
                __node* next;
            };

            __node* head;
            
            uint size;

        public:

            _list() : head(nullptr), size(0) {};

            void append(T value) {
                NEW(__node, _new, ());
                _new->data = value;
                _new->next = nullptr;

                if (this->head == nullptr)
                    this->head = _new;
                else {
                    __node* current = this->head;
                    while (current->next != nullptr)
                        current = current->next;
                    current->next = _new;
                    _new->next = current;
                }

                this->size++;
            }

            explicit operator bool() const {
                return this->head != nullptr;
            };

            _uint length() {
                return this->size;
            }

            T __getitem(_uint index) const {
                if (index >= 0 && index < this->length()) {
                    __node* current = head;
                    for (int i = 0; i < index.c; ++i)
                        current = current->next;
                    return current->data;
                }
                
                rt::IndexError.raise("list index out of range");

                T *rv = nullptr;

                return *rv;
            }

            void __remitem(_uint index) {
                if (index >= 0 && index < this->size) {
                    __node* temp = head;
                    for (int i = 0; i < index.c; i++)
                        temp = temp->next;

                    __node* prev = temp->prev;
                    __node* next = temp->next;

                    if (temp == head)
                        head = next;
                    else
                        prev->next = next;

                    if (next != nullptr)
                        next->prev = prev;

                    delete temp;
                    
                    size++;

                } else rt::IndexError.raise("list index out of range");
            };
            
            T __setitem(_uint index, T value) const {
                if (index >= 0 && index < size) {
                    __node* current = head;
                    for (int i = 0; i < index.__to_c(); ++i)
                        current = current->next;
                    current->data = value;
                } rt::IndexError.raise("list index out of range");
            }
    };
};
