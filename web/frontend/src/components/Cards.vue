<template>
  <v-row>
    <v-col cols="12">
      <v-data-table
      :headers="this.headers"
      dark
      :items="this.cardlist"
      :items-per-page="5"
      sort-by="id"
      class="elevation-1 blue-grey darken-3">
      <template v-slot:top>
      <v-toolbar rounded="" class="cyan darken-1">
        <v-toolbar-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3">
          Cards
        </v-toolbar-title>
      </v-toolbar>
      </template>
      <template v-slot:[`item.actions`]="{ item }">
        <v-icon small @click="deleteCard(item)">mdi-delete</v-icon>
        <v-icon small @click="unlockCard(item.number)">mdi-lock-open</v-icon>
    </template>
      </v-data-table>
    </v-col>
  </v-row>
</template>

<script>
import axios from "../axios";
export default {
  name: "Dashboard",
  data() {
    return {
      headers: [
        {text: "Number", align: "start", sortable: false, value: "number"},
        {text: "Type", value: "type"},
        {text: "Account ID", value: "accountid"},
        {text: "Balance", value: "balance"},
        {text: "Actions", value: "actions", sortable: false}
      ],
      cardlist: [],
    };
  },
  methods: {
    getAccounts() {
      axios.get("/api/card/info").then((response) => {
        let ctype = null;
        for (let i = 0; i < response.data.length; i++) {
          if (response.data[i].card_type === 0) {
            ctype = "Debit";
          } else {
            ctype = "Credit";
          }
          this.cardlist.push({
            number: response.data[i].card_number,
            type: ctype,
            accountid: response.data[i].account_ID,
            balance: response.data[i].balance,
          });
        }
      });
    },
    deleteCard(item){
      axios.delete("/api/card", {data:{card_number:item.number}}).then((response) => {
        if(response.data.status === "success"){
          this.$router.go();
        }
      });
    },
    unlockCard(number){
      axios.put("/api/card/unlock", {card_number:number}).then((response) => {
        console.log(response.data);
        
      });
    }
  },
  created() {
    this.getAccounts();
  },
};
</script>