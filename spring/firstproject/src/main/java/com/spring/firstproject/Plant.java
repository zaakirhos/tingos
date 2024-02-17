package com.spring.firstproject;

import org.springframework.stereotype.Component;

@Component
public class Plant {

    private String name;
    private String sciName;
    private String family;
    private String genus;

    public Plant() {
        this.name = "";
        this.sciName = "";
        this.family = "";
        this.genus = "";
    }

    public String getName() {
        return name;
    }

    public String getSciName() {
        return sciName;
    }

    public String getFamiliy() {
        return family;
    }

    public String getGenus() {
        return genus;
    }
}
