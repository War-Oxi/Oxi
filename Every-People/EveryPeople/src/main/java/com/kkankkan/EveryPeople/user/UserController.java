package com.kkankkan.EveryPeople.user;

import com.kkankkan.EveryPeople.jpa.PostRepository;
import com.kkankkan.EveryPeople.jpa.UserRepository;
import com.kkankkan.EveryPeople.user.exception.UserNotFoundException;
import com.kkankkan.EveryPeople.user.model.User;
import jakarta.validation.Valid;
import lombok.AllArgsConstructor;
import org.springframework.hateoas.EntityModel;
import org.springframework.hateoas.server.mvc.WebMvcLinkBuilder;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import java.net.URI;
import java.util.List;
import java.util.Optional;
import java.util.Set;

import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.linkTo;
import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.methodOn;

@RestController
@AllArgsConstructor
public class UserController {
	private final UserRepository userRepository;
	private final PostRepository postRepository;
	private final UserService userService;

	//전체 유저 정보 조회
	@GetMapping("/users")
	public List<User> retrieveAllUsers() {
		return userRepository.findAll();
	}

	//특정 유저 정보 조회
	@GetMapping("/users/{id}")
	public EntityModel<User> retrieveUserById(@PathVariable Integer id) {
		Optional<User> user = userRepository.findById(id);

		if(user.isEmpty())
			throw new UserNotFoundException("id:" + id);

		EntityModel<User> entityModel = EntityModel.of(user.get());

		WebMvcLinkBuilder link = linkTo(methodOn(this.getClass()).retrieveAllUsers());
		entityModel.add(link.withRel("all-users"));

		return entityModel;
	}

	//유저 생성 API
	@PostMapping("/users")
	public ResponseEntity<User> createUser(@Valid @RequestBody User user) {
		User savedUser = userRepository.save(user);

		URI location = ServletUriComponentsBuilder
			.fromCurrentContextPath()
			.path("/{id}")
			.buildAndExpand(savedUser.getUserId())
			.toUri();
		return ResponseEntity.created(location).build();
	}

	//유저 삭제
	@DeleteMapping("/users/{id}")
	public void deleteUser(@PathVariable int id) {
		userRepository.deleteById(id);
	}
}
