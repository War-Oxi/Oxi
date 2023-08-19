package com.kkankkan.EveryPeople.Friend;

import com.kkankkan.EveryPeople.jpa.UserRepository;
import com.kkankkan.EveryPeople.user.UserService;
import com.kkankkan.EveryPeople.user.model.User;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;
import java.util.Set;

@RestController
@AllArgsConstructor
public class FriendController {
	private final UserService userService;

	@PostMapping("/users/{userId}/friends/{friendId}")
	public ResponseEntity<String> addFriend(
		@PathVariable Integer userId,
		@PathVariable Integer friendId
	){
		Optional<User> userOptional = userService.getUserById(userId);
		Optional<User> friendOptional = userService.getUserById(friendId);

		if(userOptional.isPresent() && friendOptional.isPresent()) {
			User user = userOptional.get();
			User friend = friendOptional.get();

			user.addFriend(friend);
			friend.addFriend(user);

			userService.saveUser(user);
			userService.saveUser(friend);

			return ResponseEntity.status(HttpStatus.CREATED).body("Friend added successfully.");
		}
		return ResponseEntity.notFound().build();
	}

	@PostMapping("/users/{userId}/setFriends")
	public ResponseEntity<String> setFriends(
		@PathVariable Integer userId,
		@RequestBody Set<Integer> friendIds
	) {
		Optional<User> userOptional = userService.getUserById(userId);

		if (userOptional.isPresent()) {
			User user = userOptional.get();

			// Clear existing friends and add new friends
			user.getFriends().clear();
			for (Integer friendId : friendIds) {
				Optional<User> friendOptional = userService.getUserById(friendId);
				friendOptional.ifPresent(user::addFriend);
			}

			userService.saveUser(user);
			return ResponseEntity.ok("Friends set successfully.");
		}

		return ResponseEntity.notFound().build();
	}

	// 특정 유저의 친구 관계 조회
	@GetMapping("/users/{userId}/friends")
	public ResponseEntity<Set<User>> retrieveAllFriends(@PathVariable Integer userId) {
		Optional<User> userOptional = userService.getUserById(userId);

		if (userOptional.isPresent()) {
			User user = userOptional.get();
			Set<User> friends = user.getFriends();
			return ResponseEntity.ok(friends);
		}

		return ResponseEntity.notFound().build();
	}

//	// 모든 친구 관계 조회
//	@GetMapping("/users/friends")
//	public List<Friend> retrieveAllUsers() {
//		return friendRepository.findAll();
//	}

//	//특정 유저의 친구 모두 조회
//	@GetMapping("/users/{userId}/friends")
//	public List<User> getUserFriends(@PathVariable Integer userId) {
//
//		return friendService.findUserFriends(userId);
//	}
}

