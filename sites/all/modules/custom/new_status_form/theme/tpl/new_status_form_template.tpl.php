<?php

/**
 * @file
 * Theme.
 *
 * New status form theme.
 */
?>
<div class="custom-template-wrapper">
  <div class="new-body">
    <?php
    foreach ($variables['body'] as $title => $messages) {
    ?>
      <div class="new-title">
        <?php echo $title; ?>
      </div>
      <div class="new-messages">
        <?php
        foreach ($messages as $message) {
          echo $message . '<br>';
        }
        ?>
      </div>
    <?php
    }
    ?>
  </div>
</div>
