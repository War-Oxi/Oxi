//package com.kkankkan.EveryPeople.Friend;
//
//import com.kkankkan.EveryPeople.Friend.model.Friend;
//import com.kkankkan.EveryPeople.jpa.FriendRepository;
//import com.kkankkan.EveryPeople.jpa.UserRepository;
//import com.kkankkan.EveryPeople.post.model.Post;
//import com.kkankkan.EveryPeople.user.exception.UserNotFoundException;
//import com.kkankkan.EveryPeople.user.model.User;
//import lombok.AllArgsConstructor;
//import org.springframework.stereotype.Service;
//
//import java.util.List;
//import java.util.stream.Collectors;
//
//@AllArgsConstructor
//@Service
//public class FriendService {
//	private final FriendRepository friendRepository;
//	private final UserRepository userRepository;
//
//
//	public List<User> findUserFriends(Integer userId) {
//		User user = userRepository.findById(userId)
//			.orElseThrow(() -> new UserNotFoundException("User not found"));
//
//		List<Friend> friendList = friendRepository.findByUser(user);
//		return friendList.stream()
//			.map(Friend::getFriend)
//			.collect(Collectors.toList());
//	}
//}
