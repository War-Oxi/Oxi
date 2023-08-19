//package com.kkankkan.EveryPeople.Friend.model;
//
//import com.kkankkan.EveryPeople.user.model.User;
//import jakarta.persistence.*;
//import lombok.AllArgsConstructor;
//import lombok.Getter;
//import lombok.NoArgsConstructor;
//import lombok.Setter;
//
//@AllArgsConstructor
//@NoArgsConstructor
//@Setter
//@Getter
//@Entity
//public class Friend {
//
//	@Id
//	@GeneratedValue(strategy = GenerationType.IDENTITY)
//	private int id;
//
//	@ManyToOne
//	@JoinColumn(name = "user_id")
//	private User user;
//
//	@ManyToOne
//	@JoinColumn(name = "friend_id")
//	private User friend;
//
////	private int Friend;
//
////	private User friendId;
//}
//
//
