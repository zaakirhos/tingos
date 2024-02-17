package com.spring.firstproject;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
public class FirstprojectApplication {

    public static void main(String[] args) {

        //All instanced (Beans) created here
        ConfigurableApplicationContext context =  SpringApplication.run(FirstprojectApplication.class, args);

        //Instances are not created here.
        Plant p = context.getBean(Plant.class);

        //Still a 
        Plant p1 = context.getBean(Plant.class);

    }

}
