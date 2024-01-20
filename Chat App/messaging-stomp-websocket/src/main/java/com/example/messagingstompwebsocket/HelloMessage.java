/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.example.messagingstompwebsocket;

/**
 *
 * @author Student
 */
public class HelloMessage {

  private String name;
  
  private String mess;

  public HelloMessage() {
  }

  public HelloMessage(String name) {
       System.out.println(name);
    this.name = name;
  }
  
  public String getMess(){
      return this.mess;
  }
  
  public void setMess(String mess){
      this.mess = mess;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }
}