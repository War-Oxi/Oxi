package com.kkankkan.EveryPeople.post;

import com.kkankkan.EveryPeople.jpa.PostRepository;
import com.kkankkan.EveryPeople.jpa.UserRepository;
import com.kkankkan.EveryPeople.post.model.Post;
import com.kkankkan.EveryPeople.user.exception.UserNotFoundException;
import com.kkankkan.EveryPeople.user.model.User;
import jakarta.validation.Valid;
import lombok.AllArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
import com.kkankkan.EveryPeople.post.PostService;

import java.net.URI;
import java.util.List;
import java.util.Optional;

@RestController
@AllArgsConstructor
public class PostController {
	private PostRepository postRepository;
	private UserRepository userRepository;
	private PostService postService;

	@GetMapping("/posts/{userId}")
	public List<Post> retrievePostsForUser(@PathVariable int userId) {
		return postService.getUserPosts(userId);
	}

	//Post클래스의 user의 FetchType을 LAZY로 하니 작동이 안했었음
	@GetMapping("/posts")
	public List<Post> retrieveAllPosts(){
		return postRepository.findAll();
	}

	//Post 생성
	@PostMapping("/posts/{userId}")
	public ResponseEntity<Post> createPost(@PathVariable Integer id, @RequestBody Post post) {
		Optional<User> user = userRepository.findById(id);

		if(user.isEmpty())
			throw new UserNotFoundException("id : " + id);

		post.setUser(user.get());

		Post savedPost = postRepository.save(post);

		URI location = ServletUriComponentsBuilder.fromCurrentRequest()
			.path("/{id}")
			.buildAndExpand(savedPost.getPostId())
			.toUri();

		return ResponseEntity.created(location).build();
	}

	//Post DELETE
	//특정 게시글 삭제
	@DeleteMapping("/posts/{postId}")
	public void deletePostById(@PathVariable int postId){
		postRepository.deleteById(postId);
	}

	//Post DELETE
	//특정 사용자의 모든 게시글 삭제
	@DeleteMapping("/users/{userId}/posts")
	public ResponseEntity<String> deleteAllPostByUserId(@PathVariable int userId){
		postService.deleteAllPostsForUser(userId);
		return ResponseEntity.ok("All posts for the user deleted successfully");
	}
}
