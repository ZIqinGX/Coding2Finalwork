# Coding2Finalwork

## Name：Breath

### keywords：Dynamic graphics, Openframework+Arduino, audio+visual

### Panopto link
https://ual.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=e275c5c2-84a7-4e78-bff8-afc500ee9d81

This is an artwork using addon and Arduino communication with Openframework. In this project, I used addons called ofxGLSLSimplexNoise-master and ofGui to complete dynamic images on the screen. I use serial to achieve the communication with Arduino and Openframework.

The whole interactive process is when running this program, user can blow toward Arduino microphone sensor. When sensor detected change of value, and the value is detected greater than certain value I set in program, Arduino will send a message to Openframework. Because of Arduino and openframework share the same serial frequency of 9600 baud, program in openframework will generate two random number and play music. These two random numbers is key to control the change of dynamic graphics. This is why when audience blow to sensor, screen changes.

With the experience of using addon and communication Arduino and openframework, it is not difficult to construct basic frame of my final work. In making this final project, I met one biggest problem is how to let images change with the action of breath instead of using mouse. The method I took to solve this problem is applying “if” function and generate random number when openframework receive the message send by Arduino. Two random number was combined with RGB color by algorithm then the problem solved. Then the work is try many times to find best parameter range for final visual effect.

I want to name my final work as Breath. Because it changes when people breath and the sound here is very like people breathe under water. In the future, I am going to keep polishing my work, and give it more variable change.



![image](https://github.com/ZIqinGX/Coding2Finalwork/blob/main/image2%20(2).png)

![图片名称](https://github.com/ZIqinGX/Coding2Finalwork/blob/main/Testor%EF%BC%881%EF%BC%89.jpg)

![图片名称](https://github.com/ZIqinGX/Coding2Finalwork/blob/main/Testor%EF%BC%883%EF%BC%89.jpg) 
