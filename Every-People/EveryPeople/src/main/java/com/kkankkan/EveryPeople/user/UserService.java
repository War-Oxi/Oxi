package com.kkankkan.EveryPeople.user;

import com.kkankkan.EveryPeople.jpa.UserRepository;
import com.kkankkan.EveryPeople.user.exception.UserNotFoundException;
import com.kkankkan.EveryPeople.user.model.User;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class UserService {
	private final UserRepository userRepository;

	@Autowired
	public UserService(UserRepository userRepository) {
		this.userRepository = userRepository;
	}

	public Optional<User> getUserById(Integer userId) {
		return userRepository.findById(userId);
	}

	public User saveUser(User user) {
		return userRepository.save(user);
	}
}
