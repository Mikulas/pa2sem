#ifndef THREADING_H
#define THREADING_H

#include <mutex>
#include <condition_variable>


/**
 * \internal
 */
struct Thread
{
	pthread_t thr;
	int fd;
};


// /**
//  * @see http://stackoverflow.com/a/19659736/326257
//  */
// class Semaphore {
// public:
//     Semaphore(int count_ = 0) : count(count_) {}
//     void notify() {
//         unique_lock<mutex> lck(mtx);
//         ++count;
//         cv.notify_one();
//     }
//     void wait() {
//     	unique_lock<mutex> lck(mtx);

//         while(count == 0){
//             cv.wait(lck);
//         }
//         count--;
//     }

// private:
//     mutex mtx;
//     condition_variable cv;
//     int count;
// };


#endif
