package com.spring.firstproject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class Animal {

    private String name;

    @Autowired
    private Plant depPlant;

    public String getName() {
        return name;
    }

    public Plant getDepPlant() {
        return depPlant;
    }
}
