#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

namespace hf::Containers {
template<typename T>
    class ThreadSafeQueue
    {
    public:
        //I am trying to use perfect forwarding here to avoid unnecessary copies
        //so that both
        //q.Push(std::make_unique<Event>()); // moves //
        //q.Push(42); // copies //
        // can work

        void Push(T&& item)
        {
            //{
            //    std::lock_guard<std::mutex> lock(m_Mutex);
            //    m_Queue.push(std::forward<T>(item));
            //}
            //m_ConditionVariable.notify_one();
            std::lock_guard<std::mutex> lock(m_Mutex);
            m_Queue.push(std::move(item));
        }

        std::optional<T> Pop()
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            if (m_Queue.empty())
                return std::nullopt;
            T item = std::move(m_Queue.front());
            m_Queue.pop();
            return item;
        }

        //std::optional<T> PopBlocking()
        //{
        //    std::unique_lock<std::mutex> lock(m_Mutex);
        //    m_ConditionVariable.wait(lock, [this]() { return !m_Queue.empty() || m_Stopped; });

        //    if (m_Stopped && m_Queue.empty())
        //        return std::nullopt;

        //    T value = std::move(m_Queue.front());
        //    m_Queue.pop();
        //    return value;
        //}

        //void Stop()
        //{
        //    {
        //        std::lock_guard<std::mutex> lock(m_Mutex);
        //        m_Stopped = true;
        //    }
        //    m_ConditionVariable.notify_all();
        //}

    private:
        std::queue<T> m_Queue;
        mutable std::mutex m_Mutex;
        //std::condition_variable m_ConditionVariable;
        //bool m_Stopped = false;

    };
}