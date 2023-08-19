package com.kkankkan.EveryPeople.post;

import com.kkankkan.EveryPeople.jpa.PostRepository;
import com.kkankkan.EveryPeople.post.model.Post;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;

@AllArgsConstructor
@Service
public class PostService {
	private final PostRepository postRepository;

	public void deleteAllPostsForUser(int userId) {
		List<Post> postsToDelete = postRepository.findByUserUserId(userId);
		postRepository.deleteAll(postsToDelete);
	}

	public List<Post> getUserPosts(Integer userId) {
		return postRepository.findByUserUserId(userId);
	}
}
