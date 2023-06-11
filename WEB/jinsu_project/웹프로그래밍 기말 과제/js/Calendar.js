document.addEventListener("DOMContentLoaded", function() {
  const calendarBody = document.getElementById("calendarBody");
  const monthYear = document.getElementById("monthYear");
  const prevBtn = document.getElementById("prevBtn");
  const nextBtn = document.getElementById("nextBtn");
  const inputField = document.getElementById("inputField");
  const addButton = document.getElementById("addButton");
  const listItems = document.getElementById("listItems");

  let selectedDate = null; // 선택된 날짜 저장

  // 달력과 리스트 초기화
  function initialize() {
    // 현재 날짜 
    const currentDate = new Date(new Date().toLocaleString("en-US", { timeZone: "Asia/Seoul" }));
    let currentMonth = currentDate.getMonth();
    let currentYear = currentDate.getFullYear();

    // 지난 달 클릭
    prevBtn.addEventListener("click", function() {
      if (currentMonth === 0) {
        currentMonth = 11;
        currentYear -= 1;
      } else {
        currentMonth -= 1;
      }
      renderCalendar(currentYear, currentMonth);
    });

    // 다음 달 클릭
    nextBtn.addEventListener("click", function() {
      if (currentMonth === 11) {
        currentMonth = 0;
        currentYear += 1;
      } else {
        currentMonth += 1;
      }
      renderCalendar(currentYear, currentMonth);
    });

    // 리스트 추가
    addButton.addEventListener("click", function() {
      const inputValue = inputField.value.trim();
      if (inputValue !== "") {
        const listItem = document.createElement("li");
        if (selectedDate) {
          const date = selectedDate.getAttribute("data-date");
          const day = selectedDate.getAttribute("data-day");
          listItem.textContent = `${date} (${day}): ${inputValue}`;
          const deleteButton = document.createElement("button");
          deleteButton.textContent = "삭제";
          deleteButton.addEventListener("click", function() {
            listItem.remove();
          });
          listItem.appendChild(deleteButton);
        } else {
          listItem.textContent = inputValue;
        }
        listItems.appendChild(listItem);
        inputField.value = "";
        selectedDate = null; // 날짜 초기화
      }
    });

    renderCalendar(currentYear, currentMonth);
  }

  function renderCalendar(year, month) {
    calendarBody.innerHTML = "";

    monthYear.textContent = `${year}년 ${month + 1}월`;

    const daysInMonth = getDaysInMonth(year, month);

    const firstDayOfWeek = new Date(year, month, 1).getDay();

    let currentDate = 1;

    for (let row = 0; row < 6; row++) {
      const rowElement = document.createElement("tr");

      for (let col = 0; col < 7; col++) {
        const cellElement = document.createElement("td");

        if ((row === 0 && col < firstDayOfWeek) || currentDate > daysInMonth) {
          cellElement.classList.add("non-current-month");
        } else {
          cellElement.textContent = currentDate;
          const date = new Date(year, month, currentDate);
          cellElement.setAttribute("data-date", date.toLocaleDateString("ko-KR"));
          cellElement.setAttribute("data-day", getDayName(col)); // 요일 추가
          currentDate++;

          const today = new Date(new Date().toLocaleString("en-US", { timeZone: "Asia/Seoul" }));
          if (
            date.getDate() === today.getDate() &&
            date.getMonth() === today.getMonth() &&
            date.getFullYear() === today.getFullYear()
          ) {
            // 오늘 날짜 표시
            cellElement.classList.add("today");
          }

          cellElement.addEventListener("click", function() {
            const currentSelectedDate = document.querySelector(".selected-date");
            if (currentSelectedDate) {
              currentSelectedDate.classList.remove("selected-date");
            }
            this.classList.add("selected-date");
            selectedDate = this; 
            inputField.focus(); 
          });
        }

        rowElement.appendChild(cellElement);
      }

      calendarBody.appendChild(rowElement);
    }
  }

  function getDaysInMonth(year, month) {
    return new Date(year, month + 1, 0).getDate();
  }

  function getDayName(dayIndex) {
    const days = ["일", "월", "화", "수", "목", "금", "토"];
    return days[dayIndex];
  }

  initialize();
});
