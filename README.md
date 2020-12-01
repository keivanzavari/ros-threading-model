# threading-model

A repo to test the threading model in ros.
The files are taken from the answer [here](https://answers.ros.org/question/9543/rospy-threading-model/).

## C++
```bash
* rosrun threading_model publisher A
* rosrun threading_model publisher B

* rosrun threading_model subscriber C
* rosrun threading_model subscriber D
```

## Python

```bash
* rosrun threading_model ros_thread_pub A
* rosrun threading_model ros_thread_pub B

* rosrun threading_model ros_thread_sub C
* rosrun threading_model ros_thread_sub D
```

## results
If node A & B publish to the same topic and C listens,
* in python there are two threads for the messages of A & B
* in C++ there is only one thread per subscriber, so node C is running on one single thread listening to both messages of A & B. If you create a node D that also listens to this topic, then you get a new thread.
