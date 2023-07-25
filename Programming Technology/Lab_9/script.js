function displayData() {
  const dataContainer = document.getElementById('data-container');

  for (let i = 0; i < ObjInf.length; i++) {
    const obj = ObjInf[i];

    const objElement = document.createElement('div');
    objElement.classList.add('obj');

    const titleElement = document.createElement('h2');
    titleElement.textContent = obj.title;
    objElement.appendChild(titleElement);

    const descriptionElement = document.createElement('p');
    descriptionElement.textContent = obj.description;
    objElement.appendChild(descriptionElement);

    dataContainer.appendChild(objElement);
  }
}

function addObj(obj) {
  ObjInf.push(obj);

  const dataContainer = document.getElementById('data-container');
  const objElement = document.createElement('div');
  objElement.classList.add('obj');

  const titleElement = document.createElement('h2');
  titleElement.textContent = obj.title;
  objElement.appendChild(titleElement);

  const descriptionElement = document.createElement('p');
  descriptionElement.textContent = obj.description;
  objElement.appendChild(descriptionElement);

  dataContainer.appendChild(objElement);

  saveData();

}


function removeObj(id) {
  const objToRemove = document.getElementById(`obj-${id}`);
  if (objToRemove) {
    objToRemove.parentNode.removeChild(objToRemove);
  }

  ObjInf = ObjInf.filter((obj) => obj.id !== id);

  saveData();
}


function editObj(id, data) {
  const objToEdit = document.getElementById(`obj-${id}`);
  if (objToEdit) {
    const titleElement = objToEdit.querySelector('h2');
    if (data.title) {
      titleElement.textContent = data.title;
    }

    const descriptionElement = objToEdit.querySelector('p');
    if (data.description) {
      descriptionElement.textContent = data.description;
    }
  }

  ObjInf = ObjInf.map((obj) => {
    if (obj.id === id) {
      return { ...obj, ...data };
    } else {
      return obj;
    }
  });

  saveData();
}


function displayButtons() {
  const currentUser = localStorage.getItem('currentUser');

  const addButton = document.getElementById('add-button');
  const editButtons = document.querySelectorAll('.edit-button');
  const deleteButtons = document.querySelectorAll('.delete-button');

  if (currentUser) {
    addButton.disabled = false;
    editButtons.forEach((button) => (button.disabled = false));
    deleteButtons.forEach((button) => (button.disabled = false));
  } else {
    addButton.disabled = true;
    editButtons.forEach
((button) => (button.disabled = true));
    deleteButtons.forEach((button) => (button.disabled = true));
  }
}


function setupFilter() {
  const filterForm = document.getElementById('filter-form');

  const titleFilter = document.createElement('input');
  titleFilter.type = 'text';
  titleFilter.placeholder = 'Filter by title...';
  titleFilter.addEventListener('input', filterData);
  filterForm.appendChild(titleFilter);

  const dateFilter = document.createElement('select');
  dateFilter.innerHTML = `
    <option value="">Filter by date...</option>
    <option value="newest">Newest first</option>
    <option value="oldest">Oldest first</option>
  `;
  dateFilter.addEventListener('change', filterData);
  filterForm.appendChild(dateFilter);
}

function filterData() {
  const titleFilter = document.querySelector('input[type="text"]');
  const dateFilter = document.querySelector('select');
  const newData = ObjInf.filter((obj) => {
    const titleMatch = obj.title
      .toLowerCase()
      .includes(titleFilter.value.trim().toLowerCase());
    if (!titleMatch) {
      return false;
    }

    const currentDate = new Date(obj.date);
    const newestFirst = dateFilter.value === 'newest';
    const oldestFirst = dateFilter.value === 'oldest';
    
    if (newestFirst) {
      return currentDate <= Date.now();
    } else if (oldestFirst) {
      return currentDate >= Date.now();
    } else {
      return true;
    }
  });

  displayFilteredData(newData);
}

function displayFilteredData(filteredData) {
  const dataContainer = document.getElementById('data-container');
  dataContainer.innerHTML = '';

  for (let i = 0; i < filteredData.length; i++) {
    const obj = filteredData[i];

    const objElement = document.createElement('div');
    objElement.id = `obj-${obj.id}`;
    objElement.classList.add('obj');

    const titleElement = document.createElement('h2');
    titleElement.textContent = obj.title;
    objElement.appendChild(titleElement);

    const descriptionElement = document.createElement('p');
    descriptionElement.textContent = obj.description;
    objElement.appendChild(descriptionElement);

    dataContainer.appendChild(objElement);
  }
}

class View {
  constructor() {
    this.dataContainer = document.getElementById('data-container');
    this.addButton = document.getElementById('add-button');
    this.editButtons = document.querySelectorAll('.edit-button');
    this.deleteButtons = document.querySelectorAll('.delete-button');
    this.currentUser = localStorage.getItem('currentUser');
    this.filters = {
      title: '',
      date: ''
    };
  }

  displayData(data) {
    this.dataContainer.innerHTML = '';
    for (let i = 0; i < data.length; i++) {
      const obj = data[i];

      const objElement = document.createElement('div');
      objElement.id = `obj-${obj.id}`;
      objElement.classList.add('obj');

      const titleElement = document.createElement('h2');
      titleElement.textContent = obj.title;
      objElement.appendChild(titleElement);

      const descriptionElement = document.createElement('p');
      descriptionElement.textContent = obj.description;
      objElement.appendChild(descriptionElement);

      this.dataContainer.appendChild(objElement);
    }
  }

  setupFilter() {
    const filterForm = document.getElementById('filter-form');

    const titleFilter = document.createElement('input');
    titleFilter.type = 'text';
    titleFilter.placeholder = 'Filter by title...';
    titleFilter.addEventListener('input', (event) => {
      this.filters.title = event.target.value.trim().toLowerCase();
      this.filterData();
    });
    filterForm.appendChild(titleFilter);

    const dateFilter = document.createElement('select');
    dateFilter.innerHTML = `
      <option value="">Filter by date...</option>
      <option value="newest">Newest first</option>
      <option value="oldest">Oldest first</option>
    `;
    dateFilter.addEventListener('change', (event) => {
      this.filters.date = event.target.value;
      this.filterData();
    });
    filterForm.appendChild(dateFilter);
  }

  displayButtons() {
    if (this.currentUser) {
      this.addButton.disabled = false;
      this.editButtons.forEach((button) => (button.disabled = false));
      this.deleteButtons.forEach((button) => (button.disabled = false));
    } else {
      this.addButton.disabled = true;
      this.editButtons.forEach((button) => (button.disabled = true));
      this.deleteButtons.forEach((button) => (button.disabled = true));
    }
  }

  filterData() {
    const newData = ObjInf.filter((obj) => {
      const titleMatch = obj.title
        .toLowerCase()
        .includes(this.filters.title);
      if (!titleMatch) {
        return false;
      }

      const currentDate = new Date(obj.date);
      const newestFirst = this.filters.date === 'newest';
      const oldestFirst = this.filters.date === 'oldest';

      if (newestFirst) {
        return currentDate <= Date.now();
      } else if (oldestFirst) {
        return currentDate >= Date.now();
      } else {
        return true;
      }
    });

    this.displayData(newData);
  }
}

const view = new View();

function displayData() {
  view.displayData(ObjInf);
}

function addObj(obj) {
  ObjInf.push(obj);
  saveData();
  view.displayData(ObjInf);
}

function removeObj(id) {
  ObjInf = ObjInf.filter((obj) => obj.id !== id);
  saveData();
  view.displayData(ObjInf);
}

function editObj(id, data) {
  ObjInf = ObjInf.map((obj) => {
    if (obj.id === id) {
      return { ...obj, ...data };
    } else {
      return obj;
    }
  });
  saveData();
  view.displayData(ObjInf);
}

function displayButtons() {
  view.displayButtons();
}

function setupFilter() {
  view.setupFilter();
}

function filterData() {
  view.filterData();
}
