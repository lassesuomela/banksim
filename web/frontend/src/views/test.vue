<template>
  <v-data-table
    :headers="headers"
    dark
    :items="Accounts"
    sort-by="Kortti"
    class="elevation-1 blue-grey darken-3" 
  >
    <template v-slot:top>
      <v-toolbar
        rounded=""
        class="cyan darken-1"
      >
        <v-toolbar-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
        Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
            <v-dialog
            v-model="dialog"
            persistent
            max-width="600px"
            >
            <template v-slot:activator="{ on, attrs }">
                <v-btn
                color="success"
                dark
                rounded
                small
                v-bind="attrs"
                v-on="on"
                >
                <v-icon left> mdi-account-plus
                </v-icon>
                Add
                </v-btn>
            </template>
            <v-card color="blue-grey darken-3">
            <v-toolbar rounded="" class="cyan darken-1">
                
                <v-card-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
                <span class="text-h5">User Profile</span>
                </v-card-title>
            </v-toolbar>
                <v-card-text>
                    <v-container>
                        <v-row>
                            <v-col>
                                <v-text-field
                                dark
                                label="Account name"
                                name="Account name"
                                id="Account name"
                                prepend-icon="person"
                                color="cyan darken-1"
                                required
                                ></v-text-field>
                            </v-col>
                        </v-row>
                    </v-container>
                </v-card-text>
                <v-card-actions>
                    <v-spacer></v-spacer>
                        <v-btn
                            color="cyan darken-1"
                            text
                            @click="dialog = false"
                        >
                            Close
                        </v-btn>
                        <v-btn
                            color="cyan darken-1"
                            text
                            @click="dialog = false"
                        >
                            Save
                        </v-btn>
                </v-card-actions>
            </v-card>
            </v-dialog>
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
    </template>
  </v-data-table>
</template>

<script>
  export default {
    data: () => ({
      dialog: false,
      dialogDelete: false,
      headers: [
        { text: 'Account', sortable: false, value: 'Account', },
        { text: 'Kortti??', value: 'Kortti' },
        { text: 'Balance €', value: 'Balance' },
        { text: 'Actions', value: 'actions', sortable: false },
      ],
      defaultItem: { Account: '', Kortti: 0, Balance: 0, },
    }),   
    created () {
      this.initialize()
    },
    deleteItem (item) {
        
      },
    methods: {
      initialize () {
        this.Accounts = [
          { Account: 'Account 1', Kortti: 'lkm?', Balance: 6000, },
          { Account: 'Account 2', Kortti: 'ID?', Balance: 5000, },
          { Account: 'Account 3', Kortti: 1, Balance: 1000, },
          { Account: 'Account 4', Kortti: 22, Balance: 3000, },
        ]
      },
    },
  }
</script>