package com.kkankkan.EveryPeople.jpa;

import com.kkankkan.EveryPeople.post.model.Post;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface PostRepository extends JpaRepository<Post, Integer> {
	List<Post> findByUserUserId(Integer userId);
}
