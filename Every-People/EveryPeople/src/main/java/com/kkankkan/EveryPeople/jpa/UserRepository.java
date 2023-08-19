package com.kkankkan.EveryPeople.jpa;

//import com.kkankkan.EveryPeople.Friend.model.Friend;
import com.kkankkan.EveryPeople.user.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;

import java.util.List;
import java.util.Optional;
import java.util.Set;

@EnableJpaRepositories
public interface UserRepository extends JpaRepository<User, Integer> {
//	List<Friend> findByFriendByUserId(int userId);

}
