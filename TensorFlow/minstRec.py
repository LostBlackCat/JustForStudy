#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf

#���ز������ݵĶ�д���߰������ز�����д���ݣ�Ŀ¼MNIST_data������������������ϵ�ѵ���Ͳ������ݵġ�
#����ο���ǰ��Ĳ��ģ���������ԭ�򣬲������ݣ��ҵ������غ󣬷��ڵ�ǰĿ¼��MNIST_dataĿ¼�ˡ�
import tensorflow.examples.tutorials.mnist.input_data as input_data
mnist = input_data.read_data_sets("MNIST_data", one_hot=True)

#����һ������ʽ��Session��
sess = tf.InteractiveSession()

#��������ռλ��������������float��xռλ������״��[None��784]�����������ͼ�����ݵı�����ͼ���ж�����
#�ǲ���ע�ġ�����ͼ�������ά����784Χ����ô���ģ���ΪMNIST�����ͼƬ����28*28�Ĵ�С����һ����άͼ��
#չƽ�󣬷���һ������Ϊ784�������С�
#y_ռλ������״����x��ֻ��ά��ֻ��10����Ϊ��������0-9�����֣�����ֻ��10�ֽṹ��
x = tf.placeholder("float", shape=[None, 784])
y_ = tf.placeholder("float", shape=[None, 10])

#ͨ����������ʽ����Ȩ�ر����������ĳ�ʼֵ�������ڽ�ȡ��̬�ֲ��е����ݡ�
def weight_variable(shape):
  initial = tf.truncated_normal(shape, stddev=0.1)
  return tf.Variable(initial)

#ͨ����������ʽ����ƫ����������ƫ�õĳ�ʼֵ����0.1����״��shape���塣
def bias_variable(shape):
  initial = tf.constant(0.1, shape=shape)
  return tf.Variable(initial)

#����������������x�����룬W��Ȩ�أ�Ҳ�������ɾ���ˣ�strides��ʾ����������˵�ǻ������ʣ�����������
#�Ĳ�����padding��ʾ�������ݡ� Ŀǰ�����ֲ��뷽ʽ��һ����SAME����ʾ�����������ԭʼͼ����Χ����0����ʵ
#�ʾ���У���������ԭʼͼ�����ݶ�����롣һ����VALID����������󣬽��о�������У�ԭʼͼƬ���ұ߻��ߵײ�
#���������ݿ��ܳ��ֶ����������
def conv2d(x, W):
  return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME')

#�ⲽ���庯�����гػ��������ھ�������У���һ�������²����Ĳ������������������������ݵ���Ч�ֶΡ�������
#�ػ������������ֵ�ػ��;�ֵ�ػ��������2*2�ػ�������ÿ4��ֵ��ȡһ�����ػ����������������Ե���ص���
#����ԭ�ͣ�def max_pool(value, ksize, strides, padding, data_format="NHWC", name=None)����ksize��strides
#��������Ҫ����data_format���С�Ĭ��NHWC����ʾ4ά���ݣ�[batch,height,width,channels]. ���溯���е�ksize��
#strides�У�ÿ�δ�����һ��ͼƬ����Ӧ�Ĵ���������һ��ͨ�������磬ֻ�Ǻڰ�ͼƬ����������2��������2*2��
#�ػ�����Ҳ��Ӧ���²������ٶȡ�
def max_pool_2x2(x):
  return tf.nn.max_pool(x, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

#�����һ�����ˡ�shape�������Ӧ�����filter��
#����filter�ĽṹΪ��[filter_height, filter_width, in_channels, out_channels]���������˵ĸߺͿ���5��
#����ͨ��1�����ͨ����Ϊ32��Ҳ����˵����32������˲�������
W_conv1 = weight_variable([5, 5, 1, 32])
#ƫ�������壬ƫ�õ�ά����32.
b_conv1 = bias_variable([32])

#������tensor������״������������Ϊһ��28*28��ͼƬ����Ϊ�����ʱ��x��һ��[None,784]������reshape��������shape
#��[-1,28,28,1]����������ά������28,28,1��˺�õ�784�����ԣ�-1ֵ��reshape�����е����⺬��Ϳ���ӳ���None����
#����ͼƬ������batch��
x_image = tf.reshape(x, [-1,28,28,1])

#��2ά�����ֵ����һ��ƫ�ú��tensor������relu������һ�ּ���������ڼ�������кܶ�������Ҫ�о����ڴ˲���
h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1)
#�Լ�������ؽ�������²����ػ�������
h_pool1 = max_pool_2x2(h_conv1)

#�ڶ�����������˴�С5*5������ͨ����32�������ͨ����64���������ͨ���������ڶ���ľ����Ԫ��64����
W_conv2 = weight_variable([5, 5, 32, 64])
b_conv2 = bias_variable([64])

#���Ƶ�һ���������ļ���ͳػ�
h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2) + b_conv2)
h_pool2 = max_pool_2x2(h_conv2)

#ͼƬ�ߴ��С��7x7������һ����1024����Ԫ��ȫ���Ӳ㣬���ڴ�������ͼƬ���ѳػ������������reshape��һЩ
#����������Ȩ�ؾ��󣬼���ƫ�ã�Ȼ�����ʹ��ReLU���������
W_fc1 = weight_variable([7 * 7 * 64, 1024])
b_fc1 = bias_variable([1024])

#���ڶ���ػ�������ݽ��б���
h_pool2_flat = tf.reshape(h_pool2, [-1, 7*7*64])
#���о���ˣ���ƫ�ú����relu����
h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1) + b_fc1)

keep_prob = tf.placeholder("float")
#�Եڶ���������relu��Ľ��������tensorֵkeep_prob���б������߶������ά���ϵ����ݡ������Ϊ�˷�ֹ����ϣ�����������
h_fc1_drop = tf.nn.dropout(h_fc1, keep_prob)

W_fc2 = weight_variable([1024, 10])
b_fc2 = bias_variable([10])

#������һ��softmax�㣬����ǰ��ĵ���softmax regressionһ����softmax��һ����ѡ����ຯ���������ú�sigmoid���2ֵ
#�������õ�λһ��������������������棬softmax�����10����
y_conv=tf.nn.softmax(tf.matmul(h_fc1_drop, W_fc2) + b_fc2)

#ʵ��ֵy_��Ԥ��ֵy_conv����Ȼ������˻����ڶ�Ӧ��ά��������ͣ���ֵ��Ϊ�ݶ��½���������
cross_entropy = -tf.reduce_sum(y_*tf.log(y_conv))

#������ڲ���1e-4�����ݶȣ��ݶ��½�����ΪAdamOptimizer��
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)

#���ȷֱ���ѵ��ֵy_conv�Լ�ʵ�ʱ�ǩֵy_�ĵ�һ������ȡ���ֵ���Ƚ��Ƿ����
correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(y_,1))

#��correct_predictionֵ���и��㻯ת����Ȼ�����ֵ���õ����ȡ�
accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float"))

#��ͨ��tfִ��ȫ�ֱ����ĳ�ʼ����Ȼ������session����ͼ��
sess.run(tf.global_variables_initializer())
for i in range(20000):
  #��mnist��train���ݼ���ȡ��50�����ݣ����ص�batch��ʵ��һ���б�Ԫ��0��ʾͼ�����ݣ�Ԫ��1��ʾ��ǩֵ
  batch = mnist.train.next_batch(50)
  if i%100 == 0:
    #���㾫�ȣ�ͨ����ȡ��batch�е�ͼ�������Լ���ǩֵ����dropout���������뵽accuracy����ʱ���漰������ر����У�����
    #session�����㣬�õ�һ�������Ҳ����ͨ����֪��ѵ��ͼƬ���ݺͱ�ǩֵ������Ȼ���ƣ�Ȼ������ݶ��½�������Ȩֵѵ����
    train_accuracy = accuracy.eval(feed_dict={x:batch[0], y_: batch[1], keep_prob: 1.0})
    print "step %d, training accuracy %g"%(i, train_accuracy)
  #�˲���Ҫ������ѵ��W��bias�õġ�������Ȼ���ƺ��������ݶ��½��������󣬾͵���W��bias��ѵ�����ˡ�
  train_step.run(feed_dict={x: batch[0], y_: batch[1], keep_prob: 0.5})

#�Բ���ͼƬ�Ͳ��Ա�ǩֵ�Լ�������keep_prob����feed���������м������ʶ���ʡ����൱��ǰ��ѵ���õ�W��bias��Ϊ��֪������  
print "test accuracy %g"%accuracy.eval(feed_dict={x: mnist.test.images, y_: mnist.test.labels, keep_prob: 1.0})
