
// COS30008, Problem Set 4, 2021

#pragma once

#include <stdexcept>

template <typename S>
struct BNode
{
    S key;
    BNode<S> *left;
    BNode<S> *right;

    static BNode<S> NIL;

    const S &findMax() const
    {
        if (empty())
        {
            throw std::domain_error("Empty tree encountered.");
        }

        return right->empty() ? key : right->findMax();
    }

    const S &findMin() const
    {
        if (empty())
        {
            throw std::domain_error("Empty tree encountered.");
        }

        return left->empty() ? key : left->findMin();
    }

    bool remove(const S &aKey, BNode<S> *aParent)
    {
        BNode<S> *x = this;
        BNode<S> *y = aParent;

        while (!x->empty())
        {
            if (aKey == x->key)
            {
                break;
            }

            y = x; // new parent

            x = aKey < x->key ? x->left : x->right;
        }

        if (x->empty())
        {
            return false; // delete failed
        }

        if (!x->left->empty())
        {
            const S &lKey = x->left->findMax(); // find max to left
            x->key = lKey;
            x->left->remove(lKey, x);
        }
        else
        {
            if (!x->right->empty())
            {
                const S &lKey = x->right->findMin(); // find min to right
                x->key = lKey;
                x->right->remove(lKey, x);
            }
            else
            {
                if (y->left == x)
                {
                    y->left = &NIL;
                }
                else
                {
                    y->right = &NIL;
                }

                delete x; // free deleted node
            }
        }

        return true;
    }

    // PS4 starts here

    BNode()
    {
        key = S();
        left = &NIL;
        right = &NIL;
    }
    BNode(const S &aKey)
    {
        key = aKey;
        left = &NIL;
        right = &NIL;
    }
    BNode(S &&aKey)
    {
        key = move(aKey);
        left = &NIL;
        right = &NIL;
    }
    ~BNode()
    {
        if (!left->empty())
        {
            delete left;
        }
        if (!right->empty())
        {
            delete right;
        }
    }

    bool empty() const
    {
        return this == &NIL;
    }
    bool leaf() const
    {
        return (left == &NIL && right == &NIL);
    }
    size_t height() const
    {
        if (leaf())
        {
            return 0;
        }
        else
        {
            if (left->height() > right->height())
            {
                return left->height() + 1;
            }
            else
            {
                return right->height() + 1;
            }
        }
    }

    bool insert(const S &aKey)
    {
        if (empty())
        {
            return false;
        }
        if (key == aKey)
        {
            return false;
        }
        else if (key > aKey)
        {
            if (left->empty())
            {
                left = new BNode(aKey);
                return true;
            }
            else
            {
                left->insert(aKey);
            }
        }
        else if (key < aKey)
        {
            if (right->empty())
            {
                right = new BNode(aKey);
                return true;
            }
            else
            {
                right->insert(aKey);
            }
        }
    }
};

template <typename S>
BNode<S> BNode<S>::NIL;
